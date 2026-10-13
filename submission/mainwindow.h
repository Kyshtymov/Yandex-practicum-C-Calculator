#pragma once

#include "calculator.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

enum class Operation{
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
    void on_pb_1_clicked();
    void on_pb_2_clicked();
    void on_pb_3_clicked();
    void on_pb_4_clicked();
    void on_pb_5_clicked();
    void on_pb_6_clicked();
    void on_pb_7_clicked();
    void on_pb_8_clicked();
    void on_pb_9_clicked();
    void on_pb_0_clicked();
    void on_pb_clear_clicked();
    void on_pb_dot_clicked();
    void on_pb_plus_clicked();
    void on_pb_equal_clicked();
    void on_pb_minus_clicked();
    void on_pb_multiply_clicked();
    void on_pb_divide_clicked();
    void on_pb_power_clicked();
    void on_pb_reverse_clicked();
    void on_pb_delete_clicked();
    void on_pb_MS_clicked();
    void on_pb_MR_clicked();
    void on_pb_MC_clicked();

private:
    void ShowCurrentNumber(); //функция отображения текущего числа
    void ShowCurrentFormula(); //функция отображения текущей формулы
    void AddNumberToActive(const QString &button); //функция запоминания числа
    void MakeFormula(); //функция конструирования формулы
    void CheckZeroValue(); //функция для запоминания первого числа в калькулятор
    void PerformOperation(); //функция для вычисления операции
    void ClearInputNumber(); //функция по очистке текущего значения
    void ShowResult(); //функция лоя отображения результата
    Ui::MainWindow* ui;
    Calculator calculator_; //калькулятор
    Operation current_operation_ = Operation::NO_OPERATION; //текущая операция
    QString input_number_ = ""; //текущее значения в виде строки
    QString input_formula_ = ""; //текущая формула
    Number active_number_ = 0; //текущее значения в double
    Number memory_cell_ = 0; //текущее сохранённое число
    bool memory_saved_ = false; //статус памяти
};
