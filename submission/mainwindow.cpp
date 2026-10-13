#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->l_result->setText("0");
    ui->l_memory->setText("");
    ui->l_formula->setText("");
    calculator_.Set(0);
    //Установили начальные значения калькулятора
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::AddNumberToActive(const QString &button)
{
    //функция для набора числа из кнопок

    int entered_number = button.toInt();

    if (button != "."){
        if ((active_number_ == 0 || input_number_ == "" || input_number_ == "0") && (input_number_.count(".") == 0)){
            active_number_ = entered_number;
        }
        else{
            if (input_number_.count(".") == 1){
                active_number_ *= pow(10, input_number_.size() - input_number_.indexOf("."));
                active_number_ += entered_number;
                active_number_ /= pow(10, input_number_.size() - input_number_.indexOf("."));
            }
            else{
                active_number_ *= 10;
                active_number_ += entered_number;
            }
        }
        input_number_ = QString("%1").arg(active_number_);
    }
    else
        if (input_number_.isEmpty() || input_number_ == "0")
            input_number_ = "0" + button;
        else
           input_number_ += button;


    ShowCurrentNumber();
}

void MainWindow::MakeFormula()
{
    //функция для собирания формулы для l_formula
    input_formula_ = QString("%1").arg(calculator_.GetNumber());

    switch(current_operation_){
    case Operation::NO_OPERATION:
        break;
    case Operation::ADDITION:
        input_formula_ += " + ";
        break;
    case Operation::SUBTRACTION:
        input_formula_ += " − ";
        break;
    case Operation::MULTIPLICATION:
        input_formula_ += " × ";
        break;
    case Operation::DIVISION:
        input_formula_ += " ÷ ";
        break;
    case Operation::POWER:
        input_formula_ += " ^ ";
        break;
    }
    ShowCurrentFormula();
}

void MainWindow::CheckZeroValue()
{
    //для запоминания первого набора числа в калькулятор
    if (current_operation_ == Operation::NO_OPERATION)
        calculator_.Set(active_number_);

}

void MainWindow::PerformOperation()
{
    //функция для вычисления операции
    switch(current_operation_){
        case Operation::NO_OPERATION: //для запоминания первого набора числа в калькулятор
            break;
        case Operation::ADDITION:
            calculator_.Add(active_number_);
            break;
        case Operation::SUBTRACTION:
            calculator_.Sub(active_number_);
            break;
        case Operation::MULTIPLICATION:
            calculator_.Mul(active_number_);
            break;
        case Operation::DIVISION:
            calculator_.Div(active_number_);
            break;
        case Operation::POWER:
            calculator_.Pow(active_number_);
            break;
    }
}

void MainWindow::ClearInputNumber(){
    //функция для очистки входного значения
    input_number_ = "";
}

void MainWindow::ShowCurrentNumber()
{
    //функция для показа текущего значения на экран на экран
    ui->l_result->setText(input_number_);
}

void MainWindow::ShowCurrentFormula()
{
    //функция для показа формулы на экран
    ui->l_formula->setText(input_formula_);
}

void MainWindow::ShowResult()
{
    //функция для показа результата на экран
    ui->l_result->setText(QString("%1").arg(calculator_.GetNumber()));
}

//далее идет логика работы кнопок

void MainWindow::on_pb_0_clicked()
{
    AddNumberToActive(QString("0"));
}

void MainWindow::on_pb_1_clicked()
{
    AddNumberToActive(QString("1"));
}


void MainWindow::on_pb_2_clicked()
{
    AddNumberToActive(QString("2"));
}


void MainWindow::on_pb_3_clicked()
{
    AddNumberToActive(QString("3"));
}


void MainWindow::on_pb_4_clicked()
{
    AddNumberToActive(QString("4"));
}


void MainWindow::on_pb_5_clicked()
{
    AddNumberToActive(QString("5"));
}


void MainWindow::on_pb_6_clicked()
{
    AddNumberToActive(QString("6"));
}


void MainWindow::on_pb_7_clicked()
{
    AddNumberToActive(QString("7"));
}


void MainWindow::on_pb_8_clicked()
{
    AddNumberToActive(QString("8"));
}


void MainWindow::on_pb_9_clicked()
{
    AddNumberToActive(QString("9"));
}


void MainWindow::on_pb_clear_clicked()
{
    //Очищаем все значения
    ClearInputNumber();
    calculator_.Set(0);
    ui->l_result->setText("0");
    input_formula_ = "";
    active_number_ = 0;
    ui->l_formula->setText("");
    current_operation_ = Operation::NO_OPERATION;
}


void MainWindow::on_pb_dot_clicked()
{
    //функция для написания точки, ставится дополнительно запрет на более двух точек
    if (input_number_.count(".") < 1)
        AddNumberToActive(QString("."));
}



void MainWindow::on_pb_equal_clicked()
{
    //логика оператора равенства
    if (current_operation_ != Operation::NO_OPERATION){
        MakeFormula();
        input_formula_ += QString("%1").arg(active_number_) + " =";
        PerformOperation();
        input_number_ = QString("%1").arg(calculator_.GetNumber());
        active_number_ = calculator_.GetNumber();
        current_operation_ = Operation::NO_OPERATION;
        ShowResult();
        ShowCurrentFormula();
        ClearInputNumber();
    }
}


void MainWindow::on_pb_plus_clicked()
{
    CheckZeroValue();
    ClearInputNumber();
    current_operation_ = Operation::ADDITION;
    MakeFormula();
}


void MainWindow::on_pb_minus_clicked()
{
    CheckZeroValue();
    ClearInputNumber();
    current_operation_ = Operation::SUBTRACTION;
    MakeFormula();
}


void MainWindow::on_pb_multiply_clicked()
{
    CheckZeroValue();
    ClearInputNumber();
    current_operation_ = Operation::MULTIPLICATION;
    MakeFormula();
}


void MainWindow::on_pb_divide_clicked()
{
    CheckZeroValue();
    ClearInputNumber();
    current_operation_ = Operation::DIVISION;
    MakeFormula();
}


void MainWindow::on_pb_power_clicked()
{
    CheckZeroValue();
    ClearInputNumber();
    current_operation_ = Operation::POWER;
    MakeFormula();
}


void MainWindow::on_pb_reverse_clicked()
{
    //инвертируем знак текущего значения
    active_number_ *= -1;
    input_number_ = QString("%1").arg(active_number_);
    ShowCurrentNumber();
}


void MainWindow::on_pb_delete_clicked()
{
    //удаляем по одному символу в текущем значении
    if (input_number_.count(".") == 1){
        active_number_ *= pow(10, input_number_.size() - input_number_.indexOf("."));
        active_number_ = (int)active_number_ / 10;
        active_number_ /= pow(10, input_number_.size() - input_number_.indexOf(".")-1);
        }
    else{
        active_number_ = (int)active_number_ / 10;
    }

    input_number_ = QString("%1").arg(active_number_);
    if (input_number_.isEmpty())
        input_number_ = "0";
    ShowCurrentNumber();
}


void MainWindow::on_pb_MS_clicked()
{
    //сохраняем текущее значение в память
    memory_cell_ = active_number_;
    memory_saved_ = true;
    ui->l_memory->setText("M");
    ClearInputNumber();
    calculator_.Set(0);
    input_formula_ = "";
    current_operation_ = Operation::NO_OPERATION;
}


void MainWindow::on_pb_MR_clicked()
{
    //считываем из памяти текущее значени, если оно там есть
    if (memory_saved_){
        input_number_ = QString("%1").arg(memory_cell_);
        active_number_ = memory_cell_;
        ShowCurrentNumber();
    }
}


void MainWindow::on_pb_MC_clicked()
{
    //очищаем память калькулятора
    memory_saved_ = false;
    calculator_.Clear();
    ui->l_memory->setText("");
}

