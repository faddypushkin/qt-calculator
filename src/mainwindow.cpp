#include "include/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->l_memory->setText("");
    ui->l_formula->setText("");

    SetText("0");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_btn_0num_clicked() {
    AddText("0");
}

void MainWindow::on_btn_1num_clicked() {
    AddText("1");
}

void MainWindow::on_btn_2num_clicked() {
    AddText("2");
}

void MainWindow::on_btn_3num_clicked() {
    AddText("3");
}

void MainWindow::on_btn_4num_clicked() {
    AddText("4");
}

void MainWindow::on_btn_5num_clicked() {
    AddText("5");
}

void MainWindow::on_btn_6num_clicked() {
    AddText("6");
}

void MainWindow::on_btn_7num_clicked() {
    AddText("7");
}

void MainWindow::on_btn_8num_clicked() {
    AddText("8");
}

void MainWindow::on_btn_9num_clicked() {
    AddText("9");
}

void MainWindow::on_btn_point_clicked() {
    if (input_number_.contains('.')) {
        return;
    }

    AddText(".");
}

void MainWindow::on_btn_change_sign_clicked() {
    SetText(input_number_.startsWith("-") ? input_number_.mid(1)
                                          : "-" + input_number_);
}

void MainWindow::on_btn_delete_clicked() {
    if (!input_number_.size()) {
        return;
    }

    input_number_.chop(1);
    SetText(input_number_);
}

void MainWindow::on_btn_add_clicked() {
    SetOperation(Operation::ADDITION);
}

void MainWindow::on_btn_sub_clicked() {
    SetOperation(Operation::SUBTRACTION);
}

void MainWindow::on_btn_mul_clicked() {
    SetOperation(Operation::MULTIPLICATION);
}

void MainWindow::on_btn_div_clicked() {
    SetOperation(Operation::DIVISION);
}

void MainWindow::on_btn_pow_clicked() {
    SetOperation(Operation::POWER);
}

void MainWindow::on_btn_res_clicked() {
    if (current_operation_ == Operation::NO_OPERATION) {
        return;
    }

    ui->l_formula->setText(QString("%1 %2 %3 =").arg(calculator_.GetNumber())
                                                .arg(OpToString(current_operation_))
                                                .arg(active_number_));
    switch(current_operation_) {
    case Operation::ADDITION:
        calculator_.Add(active_number_);
        break;
    case Operation::DIVISION:
        calculator_.Div(active_number_);
        break;
    case Operation::MULTIPLICATION:
        calculator_.Mul(active_number_);
        break;
    case Operation::SUBTRACTION:
        calculator_.Sub(active_number_);
        break;
    case Operation::POWER:
        calculator_.Pow(active_number_);
        break;
    default:
        break;
    }

    active_number_ = calculator_.GetNumber();
    input_number_ = "";
    current_operation_ = Operation::NO_OPERATION;

    ui->l_result->setText(QString::number(active_number_));
}

void MainWindow::on_btn_clear_clicked() {
    current_operation_ = Operation::NO_OPERATION;

    ui->l_formula->setText("");
    SetText("0");
}

void MainWindow::on_btn_ms_clicked() {
    mem_ = active_number_;

    ui->l_memory->setText("M");
}

void MainWindow::on_btn_mc_clicked() {
    mem_ = std::nullopt;

    ui->l_memory->setText("");
}

void MainWindow::on_btn_mr_clicked() {
    if (!mem_.has_value()) {
        return;
    }

    active_number_ = mem_.value();
    ui->l_result->setText(QString::number(active_number_));
}

QString MainWindow::RemoveTrailingZeroes(const QString &text) {
    for (qsizetype i = 0; i < text.size(); ++i) {
        if (text[i] != '0') {
            return text.mid(i);
        }
    }
    return "";
}

QString MainWindow::NormalizeNumber(const QString &text) {
    if (text.isEmpty()) {
        return "0";
    }
    if (text.startsWith('.')) {
        return NormalizeNumber("0" + text);
    }
    if (text.startsWith('-')) {
        return "-" + NormalizeNumber(text.mid(1));
    }
    if (text.startsWith('0') && !text.startsWith("0.")) {
        return NormalizeNumber(RemoveTrailingZeroes(text));
    }
    return text;
}

QString MainWindow::OpToString(Operation op) {
    switch(op) {
    case Operation::NO_OPERATION: return "";
    case Operation::ADDITION: return "+";
    case Operation::DIVISION: return "÷";
    case Operation::MULTIPLICATION: return "×";
    case Operation::SUBTRACTION: return "−";
    case Operation::POWER: return "^";
    }
}

void MainWindow::AddText(const QString &suffix) {
    SetText(input_number_ + suffix);
}

void MainWindow::SetText(const QString &text) {
    input_number_ = NormalizeNumber(text);
    active_number_ = input_number_.toDouble();

    ui->l_result->setText(input_number_);
}

void MainWindow::SetOperation(Operation op) {
    if (current_operation_ == Operation::NO_OPERATION) {
        calculator_.Set(active_number_);
    }

    current_operation_ = op;
    ui->l_formula->setText(QString("%1 %2").arg(calculator_.GetNumber())
                               .arg(OpToString(current_operation_)));
    input_number_ = "";
}
