#include "sudokusolver.h"
#include "ui_sudokusolver.h"
#include <QString>
#include <stdbool.h>
#include <QMessageBox>


bool isSolved(int arr[][9]);
bool isPossible(int arr[][9], int k,int x,int y);
bool isInputValid(int arr[][9], int k,int x,int y);

SudokuSolver::SudokuSolver(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SudokuSolver)
{
    ui->setupUi(this);
    foreach(QLineEdit *le, findChildren<QLineEdit*>()) {
        le->setValidator(new QRegExpValidator(QRegExp("[1-9]\\d{0,0}"),this));
}
}

SudokuSolver::~SudokuSolver()
{
    delete ui;
}

void SudokuSolver::on_solveButton_clicked()
{
    QString str[9][9];
    str[0][0] = ui->box00->text();
    str[0][1] = ui->box01->text();
    str[0][2] = ui->box02->text();
    str[0][3] = ui->box03->text();
    str[0][4] = ui->box04->text();
    str[0][5] = ui->box05->text();
    str[0][6] = ui->box06->text();
    str[0][7] = ui->box07->text();
    str[0][8] = ui->box08->text();
    str[1][0] = ui->box10->text();
    str[1][1] = ui->box11->text();
    str[1][2] = ui->box12->text();
    str[1][3] = ui->box13->text();
    str[1][4] = ui->box14->text();
    str[1][5] = ui->box15->text();
    str[1][6] = ui->box16->text();
    str[1][7] = ui->box17->text();
    str[1][8] = ui->box18->text();
    str[2][0] = ui->box20->text();
    str[2][1] = ui->box21->text();
    str[2][2] = ui->box22->text();
    str[2][3] = ui->box23->text();
    str[2][4] = ui->box24->text();
    str[2][5] = ui->box25->text();
    str[2][6] = ui->box26->text();
    str[2][7] = ui->box27->text();
    str[2][8] = ui->box28->text();
    str[3][0] = ui->box30->text();
    str[3][1] = ui->box31->text();
    str[3][2] = ui->box32->text();
    str[3][3] = ui->box33->text();
    str[3][4] = ui->box34->text();
    str[3][5] = ui->box35->text();
    str[3][6] = ui->box36->text();
    str[3][7] = ui->box37->text();
    str[3][8] = ui->box38->text();
    str[4][0] = ui->box40->text();
    str[4][1] = ui->box41->text();
    str[4][2] = ui->box42->text();
    str[4][3] = ui->box43->text();
    str[4][4] = ui->box44->text();
    str[4][5] = ui->box45->text();
    str[4][6] = ui->box46->text();
    str[4][7] = ui->box47->text();
    str[4][8] = ui->box48->text();
    str[5][0] = ui->box50->text();
    str[5][1] = ui->box51->text();
    str[5][2] = ui->box52->text();
    str[5][3] = ui->box53->text();
    str[5][4] = ui->box54->text();
    str[5][5] = ui->box55->text();
    str[5][6] = ui->box56->text();
    str[5][7] = ui->box57->text();
    str[5][8] = ui->box58->text();
    str[6][0] = ui->box60->text();
    str[6][1] = ui->box61->text();
    str[6][2] = ui->box62->text();
    str[6][3] = ui->box63->text();
    str[6][4] = ui->box64->text();
    str[6][5] = ui->box65->text();
    str[6][6] = ui->box66->text();
    str[6][7] = ui->box67->text();
    str[6][8] = ui->box68->text();
    str[7][0] = ui->box70->text();
    str[7][1] = ui->box71->text();
    str[7][2] = ui->box72->text();
    str[7][3] = ui->box73->text();
    str[7][4] = ui->box74->text();
    str[7][5] = ui->box75->text();
    str[7][6] = ui->box76->text();
    str[7][7] = ui->box77->text();
    str[7][8] = ui->box78->text();
    str[8][0] = ui->box80->text();
    str[8][1] = ui->box81->text();
    str[8][2] = ui->box82->text();
    str[8][3] = ui->box83->text();
    str[8][4] = ui->box84->text();
    str[8][5] = ui->box85->text();
    str[8][6] = ui->box86->text();
    str[8][7] = ui->box87->text();
    str[8][8] = ui->box88->text();

    int arr[9][9] = {{0}}, k = 0, i = 0, j = 0;
    bool isValid = true;

    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            arr[i][j] = str[i][j].toInt();
        }
    }

    for(i = 0; i < 9 && isValid; i++){
        for(j = 0; j < 9 && isValid; j++){
            k = arr[i][j];
                if(k != 0 && !isInputValid(arr, k, i, j)){
                    QMessageBox::warning(this, "Invalid Input",
                                                "The same number can only appear once in each row, each column, and each 3x3 box!");
                  isValid = false;
                }

        }

    }

    if(isValid){
        if(arr[0][0] == 0){
            ui->box00->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[0][1] == 0){
            ui->box01->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[0][2] == 0){
            ui->box02->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[0][3] == 0){
            ui->box03->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[0][4] == 0){
            ui->box04->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[0][5] == 0){
            ui->box05->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[0][6] == 0){
            ui->box06->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[0][7] == 0){
            ui->box07->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[0][8] == 0){
            ui->box08->setStyleSheet("background-color:lightgreen;");
        }

        if(arr[1][0] == 0){
            ui->box10->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[1][1] == 0){
            ui->box11->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[1][2] == 0){
            ui->box12->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[1][3] == 0){
            ui->box13->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[1][4] == 0){
            ui->box14->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[1][5] == 0){
            ui->box15->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[1][6] == 0){
            ui->box16->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[1][7] == 0){
            ui->box17->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[1][8] == 0){
            ui->box18->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[2][0] == 0){
            ui->box20->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[2][1] == 0){
            ui->box21->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[2][2] == 0){
            ui->box22->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[2][3] == 0){
            ui->box23->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[2][4] == 0){
            ui->box24->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[2][5] == 0){
            ui->box25->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[2][6] == 0){
            ui->box26->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[2][7] == 0){
            ui->box27->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[2][8] == 0){
            ui->box28->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[3][0] == 0){
            ui->box30->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[3][1] == 0){
            ui->box31->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[3][2] == 0){
            ui->box32->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[3][3] == 0){
            ui->box33->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[3][4] == 0){
            ui->box34->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[3][5] == 0){
            ui->box35->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[3][6] == 0){
            ui->box36->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[3][7] == 0){
            ui->box37->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[3][8] == 0){
            ui->box38->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[4][0] == 0){
            ui->box40->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[4][1] == 0){
            ui->box41->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[4][2] == 0){
            ui->box42->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[4][3] == 0){
            ui->box43->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[4][4] == 0){
            ui->box44->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[4][5] == 0){
            ui->box45->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[4][6] == 0){
            ui->box46->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[4][7] == 0){
            ui->box47->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[4][8] == 0){
            ui->box48->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[5][0] == 0){
            ui->box50->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[5][1] == 0){
            ui->box51->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[5][2] == 0){
            ui->box52->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[5][3] == 0){
            ui->box53->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[5][4] == 0){
            ui->box54->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[5][5] == 0){
            ui->box55->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[5][6] == 0){
            ui->box56->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[5][7] == 0){
            ui->box57->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[5][8] == 0){
            ui->box58->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[6][0] == 0){
            ui->box60->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[6][1] == 0){
            ui->box61->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[6][2] == 0){
            ui->box62->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[6][3] == 0){
            ui->box63->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[6][4] == 0){
            ui->box64->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[6][5] == 0){
            ui->box65->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[6][6] == 0){
            ui->box66->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[6][7] == 0){
            ui->box67->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[6][8] == 0){
            ui->box68->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[7][0] == 0){
            ui->box70->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[7][1] == 0){
            ui->box71->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[7][2] == 0){
            ui->box72->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[7][3] == 0){
            ui->box73->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[7][4] == 0){
            ui->box74->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[7][5] == 0){
            ui->box75->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[7][6] == 0){
            ui->box76->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[7][7] == 0){
            ui->box77->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[7][8] == 0){
            ui->box78->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[8][0] == 0){
            ui->box80->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[8][1] == 0){
            ui->box81->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[8][2] == 0){
            ui->box82->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[8][3] == 0){
            ui->box83->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[8][4] == 0){
            ui->box84->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[8][5] == 0){
            ui->box85->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[8][6] == 0){
            ui->box86->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[8][7] == 0){
            ui->box87->setStyleSheet("background-color:lightgreen;");
        }
        if(arr[8][8] == 0){
            ui->box88->setStyleSheet("background-color:lightgreen;");
        }

        isSolved(arr);

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                str[i][j] = QString::number(arr[i][j]);
            }
        }
        ui->box00->setText(str[0][0]);
        ui->box01->setText(str[0][1]);
        ui->box02->setText(str[0][2]);
        ui->box03->setText(str[0][3]);
        ui->box04->setText(str[0][4]);
        ui->box05->setText(str[0][5]);
        ui->box06->setText(str[0][6]);
        ui->box07->setText(str[0][7]);
        ui->box08->setText(str[0][8]);
        ui->box10->setText(str[1][0]);
        ui->box11->setText(str[1][1]);
        ui->box12->setText(str[1][2]);
        ui->box13->setText(str[1][3]);
        ui->box14->setText(str[1][4]);
        ui->box15->setText(str[1][5]);
        ui->box16->setText(str[1][6]);
        ui->box17->setText(str[1][7]);
        ui->box18->setText(str[1][8]);
        ui->box20->setText(str[2][0]);
        ui->box21->setText(str[2][1]);
        ui->box22->setText(str[2][2]);
        ui->box23->setText(str[2][3]);
        ui->box24->setText(str[2][4]);
        ui->box25->setText(str[2][5]);
        ui->box26->setText(str[2][6]);
        ui->box27->setText(str[2][7]);
        ui->box28->setText(str[2][8]);
        ui->box30->setText(str[3][0]);
        ui->box31->setText(str[3][1]);
        ui->box32->setText(str[3][2]);
        ui->box33->setText(str[3][3]);
        ui->box34->setText(str[3][4]);
        ui->box35->setText(str[3][5]);
        ui->box36->setText(str[3][6]);
        ui->box37->setText(str[3][7]);
        ui->box38->setText(str[3][8]);
        ui->box40->setText(str[4][0]);
        ui->box41->setText(str[4][1]);
        ui->box42->setText(str[4][2]);
        ui->box43->setText(str[4][3]);
        ui->box44->setText(str[4][4]);
        ui->box45->setText(str[4][5]);
        ui->box46->setText(str[4][6]);
        ui->box47->setText(str[4][7]);
        ui->box48->setText(str[4][8]);
        ui->box50->setText(str[5][0]);
        ui->box51->setText(str[5][1]);
        ui->box52->setText(str[5][2]);
        ui->box53->setText(str[5][3]);
        ui->box54->setText(str[5][4]);
        ui->box55->setText(str[5][5]);
        ui->box56->setText(str[5][6]);
        ui->box57->setText(str[5][7]);
        ui->box58->setText(str[5][8]);
        ui->box60->setText(str[6][0]);
        ui->box61->setText(str[6][1]);
        ui->box62->setText(str[6][2]);
        ui->box63->setText(str[6][3]);
        ui->box64->setText(str[6][4]);
        ui->box65->setText(str[6][5]);
        ui->box66->setText(str[6][6]);
        ui->box67->setText(str[6][7]);
        ui->box68->setText(str[6][8]);
        ui->box70->setText(str[7][0]);
        ui->box71->setText(str[7][1]);
        ui->box72->setText(str[7][2]);
        ui->box73->setText(str[7][3]);
        ui->box74->setText(str[7][4]);
        ui->box75->setText(str[7][5]);
        ui->box76->setText(str[7][6]);
        ui->box77->setText(str[7][7]);
        ui->box78->setText(str[7][8]);
        ui->box80->setText(str[8][0]);
        ui->box81->setText(str[8][1]);
        ui->box82->setText(str[8][2]);
        ui->box83->setText(str[8][3]);
        ui->box84->setText(str[8][4]);
        ui->box85->setText(str[8][5]);
        ui->box86->setText(str[8][6]);
        ui->box87->setText(str[8][7]);
        ui->box88->setText(str[8][8]);
    }
}

bool isInputValid(int arr[][9],int k,int x,int y){
   int i = 0, j = 0;
   for(i = 0; i < 9; i++){
      if(i != x && arr[i][y] == k){
            return false;
      }
   }

   for(j = 0; j < 9; j++){
      if(j != y && arr[x][j] == k){
         if(x != i){
            return false;
         }
      }
   }

   for(i = 3 * (x / 3); i < 3 * (x / 3 + 1); i++){
      for(j = 3 * (y / 3); j < 3 * (y / 3 + 1); j++){
         if(arr[i][j] == k){
            if(i != x | j != y){
               return false;
            }
         }
      }
   }

   return true;
}


bool isSolved(int arr[][9]){
   int i, j, k;
   for(i = 0; i < 9; i++){
      for(j = 0; j < 9; j++){
         if(arr[i][j] == 0){
            for(k = 1; k <= 9; k++){
               if(isPossible(arr, k, j, i)){
                  arr[i][j] = k;
                  if(isSolved(arr)){
                     return true;
                  }
               }
            }
            arr[i][j] = 0;
            return false;
         }
      }
   }
   return true;
}


bool isPossible(int arr[][9],int k,int x,int y){
   int i = 0, j = 0;
   for(j = 0; j < 9; j++){
      if(arr[y][j] == k){
         return false;
      }
   }

   for(i = 0; i < 9; i++){
      if(arr[i][x] == k){
         return false;
      }
   }

   for(i = 3 * (y / 3); i < 3 * (y / 3 + 1); i++){
      for(j = 3 * (x / 3); j < 3 * (x / 3 + 1); j++){
         if(arr[i][j] == k){
            return false;
         }
      }
   }
   return true;
}

void SudokuSolver::on_clearButton_clicked()
{
    foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
    le->clear();
    le->setStyleSheet("background-color:white;");
    }
}
