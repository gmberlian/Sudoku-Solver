#ifndef SUDOKUSOLVER_H
#define SUDOKUSOLVER_H

#include <QMainWindow>

namespace Ui {
    class SudokuSolver;
}

class SudokuSolver : public QMainWindow
{
    Q_OBJECT

public:
    explicit SudokuSolver(QWidget *parent = 0);
    ~SudokuSolver();

private:
    Ui::SudokuSolver *ui;

private slots:
    void on_clearButton_clicked();
    void on_solveButton_clicked();
};

#endif // SUDOKUSOLVER_H
