#pragma once

#include <optional>
#include <QMainWindow>

#include "calculator.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

enum class Operation {
    NO_OPERATION,
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    POWER
};

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:

    void on_btn_0num_clicked();
    void on_btn_1num_clicked();
    void on_btn_2num_clicked();
    void on_btn_3num_clicked();
    void on_btn_4num_clicked();
    void on_btn_5num_clicked();
    void on_btn_6num_clicked();
    void on_btn_7num_clicked();
    void on_btn_8num_clicked();
    void on_btn_9num_clicked();

    void on_btn_point_clicked();
    void on_btn_change_sign_clicked();
    void on_btn_delete_clicked();

    void on_btn_add_clicked();
    void on_btn_sub_clicked();
    void on_btn_mul_clicked();
    void on_btn_div_clicked();
    void on_btn_pow_clicked();

    void on_btn_res_clicked();
    void on_btn_clear_clicked();

    void on_btn_ms_clicked();
    void on_btn_mc_clicked();
    void on_btn_mr_clicked();

private:
    static QString RemoveTrailingZeroes(const QString &text);
    static QString NormalizeNumber(const QString &text);
    static QString OpToString(Operation op);

    void AddText(const QString& suffix);
    void SetText(const QString& text);
    void SetOperation(Operation op);

private:
    Ui::MainWindow* ui;
    Calculator calculator_;
    QString input_number_;
    Number active_number_;

    std::optional<Number> mem_;

    Operation current_operation_ = Operation::NO_OPERATION;
};
