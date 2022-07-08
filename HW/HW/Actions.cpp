#include "Actions.h"

BoardActions::BoardActions(Scene* s, vector<vector<myButton*>>& Cheeses, int** chessboard, double SI, int** com)
{
    sc = s;
    SIZE = SI;
    board = chessboard;
    comp = com;
    for (int i = 0; i < Cheeses.size(); i++)
    {
        cheeses.push_back(Cheeses[i]);
    }
}

//一个贪婪判断法，比如有一个三个棋子组成的直线，那么对这三个棋子都会进行一次判断，虽然增加了复杂度，但是遍历棋盘进行消除更为方便
//被消除则置0
//@param int** &chessboard: 数字棋盘，每个数字代表棋子种类
//@param int** &comp: 中间量，存储不断被置0的数字棋盘，最后再赋给chessboard，否则原始数据改变了就无法判断
//@param int i: 第i行
//@param int j: 第j列
//ret: int 返回flag
//23123123
float BoardActions::ScanAllAndDelete(int i, int j)
{
    //flag: 用于记录是几消的标志
    float flag = 0;
    double cate = 0.0;
    if (board[i][j] == 1)
    {
        cate = ATTACK;
    }
    else if (board[i][j] == 2)
    {
        cate = RECOVER;
    }
    else if (board[i][j] == 3)
    {
        cate = ANGER;
    }

    if (board[i][j] == 0 || i < 0 || j < 0)
    {
        flag = -1;
    }

    //这里全用if，因为可能产生包含，比如三个一排包含在四个一排，多次判断后得出最大值
    //一消，三个排列
    if (j < 7 && j > 0 && board[i][j] == board[i][j - 1]
        && board[i][j - 1] == board[i][j + 1])
    {
        flag = 1;
    }

    if (j > 1 && board[i][j] == board[i][j - 1]
        && board[i][j - 1] == board[i][j - 2])
    {
        flag = 1;
    }
    if (j < 7 && board[i][j] == board[i][j + 1]
        && board[i][j + 1] == board[i][j + 2])
    {
        flag = 1;
    }
    if (i < 6 && i > 0 && board[i - 1][j] == board[i][j]
        && board[i][j] == board[i + 1][j])
    {
        flag = 1;
    }
    if (i > 1 && board[i - 2][j] == board[i][j]
        && board[i][j] == board[i - 1][j])
    {
        flag = 1;
    }
    if (i < 5 && board[i + 1][j] == board[i][j]
        && board[i][j] == board[i + 2][j])
    {
        flag = 1;
    }
    //二消，四个连着
    if (j > 2 && board[i][j] == board[i][j - 1]
        && board[i][j - 1] == board[i][j - 2]
        && board[i][j - 2] == board[i][j - 3])
    {
        flag = 2;
    }
    if (j < 7 && j > 1 && board[i][j] == board[i][j - 1]
        && board[i][j - 1] == board[i][j - 2]
        && board[i][j - 2] == board[i][j + 1])
    {
        flag = 2;
    }
    if (j < 6 && j > 0 && board[i][j] == board[i][j - 1]
        && board[i][j - 1] == board[i][j + 1]
        && board[i][j + 1] == board[i][j + 2])
    {
        flag = 2;
    }
    if (j < 5 && board[i][j] == board[i][j + 1]
        && board[i][j + 1] == board[i][j + 2]
        && board[i][j + 2] == board[i][j + 3])
    {
        flag = 2;
    }
    if (j > 2 && board[i][j] == board[i][j - 1]
        && board[i][j - 1] == board[i][j - 2]
        && board[i][j - 2] == board[i][j - 3])
    {
        flag = 2;
    }
    if (j < 7 && j > 1 && board[i][j] == board[i][j - 1]
        && board[i][j - 1] == board[i][j - 2]
        && board[i][j - 2] == board[i][j + 1])
    {
        flag = 2;
    }
    if (j < 6 && j > 0 && board[i][j] == board[i][j - 1]
        && board[i][j - 1] == board[i][j + 1]
        && board[i][j + 1] == board[i][j + 2])
    {
        flag = 2;
    }
    if (j < 5 && board[i][j] == board[i][j + 1]
        && board[i][j + 1] == board[i][j + 2]
        && board[i][j + 2] == board[i][j + 3])
    {
        flag = 2;
    }
    //三消，五个除了直线的所有排列
    //十字形
    if (i < 6 && j < 7 && i > 0 && j > 0 && board[i][j] == board[i][j - 1]
        && board[i][j - 1] == board[i][j + 1]
        && board[i][j + 1] == board[i - 1][j]
        && board[i - 1][j] == board[i + 1][j])
    {
        flag = 3;
    }
    if (j < 7 && i > 1 && j > 0 && board[i][j] == board[i - 1][j]
        && board[i - 1][j] == board[i - 1][j - 1]
        && board[i - 1][j - 1] == board[i - 1][j + 1]
        && board[i - 1][j + 1] == board[i - 2][j])
    {
        flag = 3;
    }
    if (i < 5 && j < 7 && j > 0 && board[i][j] == board[i + 1][j]
        && board[i + 1][j] == board[i + 1][j - 1]
        && board[i + 1][j - 1] == board[i + 1][j + 1]
        && board[i + 1][j + 1] == board[i + 2][j])
    {
        flag = 3;
    }
    if (i < 6 && i > 0 && j > 1 && board[i][j] == board[i][j - 1]
        && board[i][j - 1] == board[i][j - 2]
        && board[i][j - 2] == board[i + 1][j - 1]
        && board[i + 1][j - 1] == board[i - 1][j - 1])
    {
        flag = 3;
    }
    if (i < 6 && j < 6 && i > 0 && board[i][j] == board[i][j + 1]
        && board[i][j + 1] == board[i][j + 2]
        && board[i][j + 2] == board[i + 1][j + 1]
        && board[i + 1][j + 1] == board[i - 1][j + 1])
    {
        flag = 3;
    }
    //竖着的T
    if (j < 7 && i > 1 && j > 0 && board[i][j] == board[i][j - 1]
        && board[i][j - 1] == board[i][j + 1]
        && board[i][j + 1] == board[i - 1][j]
        && board[i - 1][j] == board[i - 2][j])
    {
        flag = 3;
    }
    if (i < 5 && j < 7 && j > 0 && board[i][j] == board[i][j - 1]
        && board[i][j - 1] == board[i][j + 1]
        && board[i][j + 1] == board[i + 1][j]
        && board[i + 1][j] == board[i + 2][j])
    {
        flag = 3;
    }
    if (j < 6 && i > 1 && board[i][j] == board[i][j + 1]
        && board[i][j + 1] == board[i][j + 2]
        && board[i][j + 2] == board[i - 1][j + 1]
        && board[i - 1][j + 1] == board[i - 2][j + 1])
    {
        flag = 3;
    }
    if (i < 5 && j > 1 && board[i][j] == board[i][j - 1]
        && board[i][j - 1] == board[i][j - 2]
        && board[i][j - 2] == board[i + 1][j - 1]
        && board[i + 1][j - 1] == board[i + 2][j - 1])
    {
        flag = 3;
    }
    if (i < 5 && j < 6 && board[i][j] == board[i][j + 1]
        && board[i][j + 1] == board[i][j + 2]
        && board[i][j + 2] == board[i + 1][j + 1]
        && board[i + 1][j + 1] == board[i + 2][j + 1])
    {
        flag = 3;
    }
    if (i > 1 && j > 1 && board[i][j] == board[i][j - 1]
        && board[i][j - 1] == board[i][j - 2]
        && board[i][j - 2] == board[i - 1][j - 1]
        && board[i - 1][j - 1] == board[i - 2][j - 1])
    {
        flag = 3;
    }
    if (i > 1 && j > 0 && board[i][j] == board[i - 1][j]
        && board[i - 1][j] == board[i - 2][j]
        && board[i - 2][j] == board[i - 2][j + 1]
        && board[i - 2][j + 1] == board[i - 2][j - 1])
    {
        flag = 3;
    }
    if (i < 5 && j < 6 && j > 0 && board[i][j] == board[i + 1][j]
        && board[i + 1][j] == board[i + 2][j]
        && board[i + 2][j] == board[i + 2][j - 1]
        && board[i + 2][j - 1] == board[i + 2][j + 1])
    {
        flag = 3;
    }
    if (i < 6 && j < 7 && i > 0 && j > 0 && board[i][j] == board[i - 1][j]
        && board[i - 1][j] == board[i + 1][j]
        && board[i + 1][j] == board[i + 1][j + 1]
        && board[i + 1][j + 1] == board[i + 1][j - 1])
    {
        flag = 3;
    }
    if (i < 5 && j < 7 && i > 0 && j > 0 && board[i][j] == board[i + 1][j]
        && board[i + 1][j] == board[i + 2][j]
        && board[i + 2][j] == board[i - 1][j - 1]
        && board[i - 1][j - 1] == board[i - 1][j + 1])
    {
        flag = 3;
    }
    //横着的T
    if (i < 6 && j < 6 && i > 0 && board[i][j] == board[i - 1][j]
        && board[i - 1][j] == board[i + 1][j]
        && board[i][j] == board[i][j + 1]
        && board[i][j + 1] == board[i][j + 2])
    {
        flag = 3;
    }
    if (i < 6 && i > 0 && j > 1 && board[i][j] == board[i - 1][j]
        && board[i - 1][j] == board[i + 1][j]
        && board[i][j] == board[i][j - 1]
        && board[i][j - 1] == board[i][j - 2])
    {
        flag = 3;
    }

    if (i < 6 && j < 7 && i > 0 && j > 0 && board[i][j] == board[i][j + 1]
        && board[i][j + 1] == board[i][j - 1]
        && board[i][j - 1] == board[i + 1][j - 1]
        && board[i + 1][j - 1] == board[i - 1][j - 1])
    {
        flag = 3;
    }
    if (i < 6 && j < 7 && i > 0 && j > 0 && board[i][j] == board[i][j + 1]
        && board[i][j + 1] == board[i][j - 1]
        && board[i][j + 1] == board[i + 1][j + 1]
        && board[i + 1][j + 1] == board[i - 1][j + 1])
    {
        flag = 3;
    }
    if (i < 6 && i > 0 && j > 1 && board[i][j] == board[i][j - 1]
        && board[i][j - 1] == board[i][j - 2]
        && board[i][j - 2] == board[i + 1][j - 2]
        && board[i + 1][j - 2] == board[i - 1][j - 2])
    {
        flag = 3;
    }
    if (i < 5 && j < 6 && i > 0 && board[i][j] == board[i][j + 1]
        && board[i][j + 1] == board[i][j + 2]
        && board[i][j + 2] == board[i + 1][j + 2]
        && board[i + 1][j + 2] == board[i - 1][j + 2])
    {
        flag = 3;
    }
    if (j < 6 && i > 1 && board[i][j] == board[i - 1][j]
        && board[i - 1][j] == board[i - 2][j]
        && board[i - 1][j] == board[i - 1][j + 1]
        && board[i - 1][j + 1] == board[i - 1][j + 2])
    {
        flag = 3;
    }
    if (i > 1 && j > 1 && board[i][j] == board[i - 1][j]
        && board[i - 1][j] == board[i - 2][j]
        && board[i - 1][j] == board[i - 1][j - 1]
        && board[i - 1][j - 1] == board[i - 1][j - 2])
    {
        flag = 3;
    }
    if (i < 5 && j < 6 && board[i][j] == board[i + 1][j]
        && board[i + 1][j] == board[i + 2][j]
        && board[i + 1][j] == board[i + 1][j + 1]
        && board[i + 1][j + 1] == board[i + 1][j + 2])
    {
        flag = 3;
    }
    if (i < 5 && j>1 && board[i][j] == board[i + 1][j]
        && board[i + 1][j] == board[i + 2][j]
        && board[i + 1][j] == board[i + 1][j - 1]
        && board[i + 1][j - 1] == board[i + 1][j - 2])
    {
        flag = 3;
    }
    //z直角
    if (i < 5 && j < 6 && board[i][j] == board[i][j + 1]
        && board[i][j + 1] == board[i][j + 2]
        && board[i][j + 2] == board[i + 1][j]
        && board[i + 1][j] == board[i + 2][j])
    {
        flag = 3;
    }
    if (j < 6 && i > 1 && board[i][j] == board[i][j + 1]
        && board[i][j + 1] == board[i][j + 2]
        && board[i][j + 2] == board[i - 1][j]
        && board[i - 1][j] == board[i - 2][j])
    {
        flag = 3;
    }
    if (i < 5 && j > 1 && board[i][j] == board[i][j - 1]
        && board[i][j - 1] == board[i][j - 2]
        && board[i][j - 2] == board[i + 1][j]
        && board[i + 1][j] == board[i + 2][j])
    {
        flag = 3;
    }
    if (i > 1 && j > 1 && board[i][j] == board[i][j - 1]
        && board[i][j - 1] == board[i][j - 2]
        && board[i][j - 2] == board[i - 1][j]
        && board[i - 1][j] == board[i - 2][j])
    {
        flag = 3;
    }
    if (i < 5 && j < 6 && board[i][j] == board[i + 1][j]
        && board[i + 1][j] == board[i + 2][j]
        && board[i + 2][j] == board[i + 2][j + 1]
        && board[i + 2][j + 1] == board[i + 2][j + 2])
    {
        flag = 3;
    }
    if (i < 5 && j > 1 && board[i][j] == board[i + 1][j]
        && board[i + 1][j] == board[i + 2][j]
        && board[i + 2][j] == board[i + 2][j - 1]
        && board[i + 2][j - 1] == board[i + 2][j - 2])
    {
        flag = 3;
    }
    if (i < 6 && j < 5 && i > 0 && board[i - 1][j] == board[i + 1][j]
        && board[i + 1][j] == board[i][j]
        && board[i][j] == board[i + 1][j + 1]
        && board[i + 1][j + 1] == board[i + 1][j + 2])
    {
        flag = 3;
    }
    if (i < 6 && i > 0 && j > 1 && board[i - 1][j] == board[i + 1][j]
        && board[i + 1][j] == board[i][j]
        && board[i][j] == board[i + 1][j - 1]
        && board[i + 1][j - 1] == board[i + 1][j - 2])
    {
        flag = 3;
    }
    if (i < 5 && j > 1 && board[i][j] == board[i][j - 1]
        && board[i][j - 1] == board[i][j - 2]
        && board[i][j - 2] == board[i + 1][j - 2]
        && board[i + 1][j - 2] == board[i + 2][j - 2])
    {
        flag = 3;
    }
    if (i > 1 && j > 1 && board[i][j] == board[i][j - 1]
        && board[i][j - 1] == board[i][j - 2]
        && board[i][j - 2] == board[i - 1][j - 2]
        && board[i - 1][j - 2] == board[i - 2][j - 2])
    {
        flag = 3;
    }
    if (i < 5 && j < 7 && j > 0 && board[i][j] == board[i][j + 1]
        && board[i][j + 1] == board[i][j - 1]
        && board[i][j - 1] == board[i + 1][j - 1]
        && board[i + 1][j - 1] == board[i + 2][j - 1])
    {
        flag = 3;
    }
    if (j < 7 && i > 1 && j > 0 && board[i][j] == board[i][j + 1]
        && board[i][j + 1] == board[i][j - 1]
        && board[i][j - 1] == board[i - 1][j - 1]
        && board[i - 1][j - 1] == board[i - 2][j - 1])
    {
        flag = 3;
    }
    if (i > 1 && j > 1 && board[i][j] == board[i - 1][j]
        && board[i - 1][j] == board[i - 2][j]
        && board[i - 2][j] == board[i - 2][j - 1]
        && board[i - 2][j - 1] == board[i - 2][j - 2])
    {
        flag = 3;
    }
    if (j < 6 && i > 1 && board[i][j] == board[i - 1][j]
        && board[i - 1][j] == board[i - 2][j]
        && board[i - 2][j] == board[i - 2][j + 1]
        && board[i - 2][j + 1] == board[i - 2][j + 2])
    {
        flag = 3;
    }
    if (i < 6 && j < 6 && i > 0 && board[i][j] == board[i - 1][j]
        && board[i - 1][j] == board[i + 1][j]
        && board[i + 1][j] == board[i - 1][j + 1]
        && board[i - 1][j + 1] == board[i - 1][j + 2])
    {
        flag = 3;
    }
    if (i < 6 && i > 0 && j > 1 && board[i][j] == board[i - 1][j]
        && board[i - 1][j] == board[i + 1][j]
        && board[i + 1][j] == board[i - 1][j - 1]
        && board[i - 1][j - 1] == board[i - 1][j - 2])
    {
        flag = 3;
    }
    if (j < 6 && i > 1 && board[i][j] == board[i][j + 1]
        && board[i][j + 1] == board[i][j + 2]
        && board[i][j + 2] == board[i - 1][j + 2]
        && board[i - 1][j + 2] == board[i - 2][j + 2])
    {
        flag = 3;
    }
    if (j < 6 && i > 1 && j > 1 && board[i][j] == board[i][j + 1]
        && board[i][j + 1] == board[i][j + 2]
        && board[i][j + 2] == board[i - 1][j - 2]
        && board[i - 1][j - 2] == board[i - 2][j - 2])
    {
        flag = 3;
    }
    if (j < 7 && i > 1 && j > 0 && board[i][j] == board[i][j + 1]
        && board[i][j + 1] == board[i][j - 1]
        && board[i][j - 1] == board[i - 1][j + 1]
        && board[i - 1][j + 1] == board[i - 2][j + 1])
    {
        flag = 3;
    }
    if (j < 7 && i > 1 && j > 0 && board[i][j] == board[i][j + 1]
        && board[i][j + 1] == board[i][j - 1]
        && board[i][j - 1] == board[i - 1][j - 1]
        && board[i - 1][j - 1] == board[i - 2][j - 1])
    {
        flag = 3;
    }
    //四消，五个一条直线
    if (j > 3 && board[i][j] == board[i][j - 1]
        && board[i][j - 1] == board[i][j - 2]
        && board[i][j - 2] == board[i][j - 3]
        && board[i][j - 3] == board[i][j - 4])
    {
        flag = 4;
    }
    if (j < 7 && j > 2 && board[i][j] == board[i][j - 1]
        && board[i][j - 1] == board[i][j - 2]
        && board[i][j - 2] == board[i][j - 3]
        && board[i][j - 3] == board[i][j + 1])
    {
        flag = 4;
    }
    if (j < 6 && j > 1 && board[i][j] == board[i][j - 1]
        && board[i][j - 1] == board[i][j - 2]
        && board[i][j - 2] == board[i][j + 1]
        && board[i][j + 1] == board[i][j + 2])
    {
        flag = 4;
    }
    if (j < 5 && j > 0 && board[i][j] == board[i][j - 1]
        && board[i][j - 1] == board[i][j + 1]
        && board[i][j + 1] == board[i][j + 2]
        && board[i][j + 2] == board[i][j + 3])
    {
        flag = 4;
    }
    if (board[i][j] == board[i][j + 1]
        && board[i][j + 1] == board[i][j + 2]
        && board[i][j + 2] == board[i][j + 3]
        && board[i][j + 3] == board[i][j + 4])
    {
        flag = 4;
    }
    if (i > 3 && board[i][j] == board[i - 1][j]
        && board[i - 1][j] == board[i - 2][j]
        && board[i - 2][j] == board[i - 3][j]
        && board[i - 3][j] == board[i - 4][j])
    {
        flag = 4;
    }
    if (i < 6 && i > 2 && board[i][j] == board[i - 1][j]
        && board[i - 1][j] == board[i - 2][j]
        && board[i - 2][j] == board[i - 3][j]
        && board[i - 3][j] == board[i + 1][j])
    {
        flag = 4;
    }
    if (i < 5 && i > 1 && board[i][j] == board[i - 1][j]
        && board[i - 1][j] == board[i - 2][j]
        && board[i - 2][j] == board[i + 1][j]
        && board[i + 1][j] == board[i + 2][j])
    {
        flag = 4;
    }
    if (i < 4 && i > 0 && board[i][j] == board[i - 1][j]
        && board[i - 1][j] == board[i + 1][j]
        && board[i + 1][j] == board[i + 2][j]
        && board[i + 2][j] == board[i + 3][j])
    {
        flag = 4;
    }
    if (i < 3 && board[i][j] == board[i + 1][j]
        && board[i + 1][j] == board[i + 2][j]
        && board[i + 2][j] == board[i + 3][j]
        && board[i + 3][j] == board[i + 4][j])
    {
        flag = 4;
    }

    //给comp赋值，如果不需要消除则不变，需要则置0
    if (flag > 0)
    {
        comp[i][j] = 0;
        if (cate == 0.2)
        {
            totalAttack += flag ;
        }
        else if(cate == 0.4)
        {
            totalRecover += 3 * flag;
        }
        else if (cate == 0.6)
        {
            totalAnger += 4 * flag;
        }
        if (!isInit)
        {
            ch->Boomb(cheeses[i][j]);
            //cheeses[i][j]->s->add(gcnew FadeOut(2));
            //sequence->add(ch->Boomb(cheeses[i][j]));
            //cheeses[i][j]->changeToNull();
            //cout << flag << endl;
            if (flag == 1)
                three++;
            else if (flag == 2)
                four++;
            else if (flag == 3)
                five++;
            else if (flag == 4)
                diamond++;
        }
        
       
    }
    else
    {
        comp[i][j] = board[i][j];
    }
    return flag;
}

//让所有被消除地方的棋子自由下落,从下往上扫描
//@param int** &chessboard: 数字棋盘，每个数字代表棋子种类
//@param vector<vector<QLabel*>> &Cheeses: 对象棋盘，二维向量，存储QLabel对象
//@param int rows: 行数
//@param int cols: 列数
//@param int SIZE: 每个间隔大小
//@param int UP: 棋盘上边界的Y坐标
//ret: void
void BoardActions::FallAmongAll()
{
    for (int i = cheeses.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j < cheeses.size() + 1; j++)
        {
            GraviticallyFall(i, j);

        }
    }
}

//填充函数，把所有为0的地方随机生成一个棋子来填充
//@param int** &chessboard: 数字棋盘，每个数字代表棋子种类
//@param vector<vector<QLabel*>> &Cheeses: 对象棋盘，二维向量，存储QLabel对象
//@param int rows: 行数
//@param int cols: 列数
//@param int SIZE: 每个间隔大小
//@param int UP: 棋盘上边界的Y坐标
//ret: void
void BoardActions::padding()
{
    Sword s;
    Drug d;
    Anger a;
    for (int i = cheeses.size() - 1; i >= 0; i--)
    {
        for (int j = cheeses.size(); j >= 0; j--)
        {
            if (board[i][j] == 0)
            {
                //随机生成棋子
                //srand(time(NULL));
                int var = rand() % 3 + 1;

                board[i][j] = var;
                //填充图片
            }
        }
    }
}

void BoardActions::afterDeletePadding()
{
    Sword s;
    Drug d;
    Anger a;
    for (int j = cheeses.size(); j >= 0; j--)
    {
        if (board[0][j] == 0)
        {
                //随机生成棋子
            //srand(time(NULL));
            ch->Recover(cheeses[0][j]);
            int var = rand() % 3 + 1;
            if (var == 1)
            {
                cheeses[0][j]->changeToSword();
               
            }
            else if (var == 2)
            {
                cheeses[0][j]->changeToDrug();
               
            }
            else if (var == 3)
            {
                cheeses[0][j]->changeToAnger();
                
            }
            board[0][j] = var;
                //填充图片
        }
    }
    FallAmongAll();
    //cout << "----after fall------" << endl;
    //print(board, 7, 8);
    //cout << cheeses[0][3]->getPosY();
}

//向下位移，上面个棋子和下面个交换
//@param int** &chessboard: 数字棋盘，每个数字代表棋子种类
//@param vector<vector<QLabel*>> &Cheeses: 对象棋盘，二维向量，存储QLabel对象
//@param int rows: 行数
//@param int cols: 列数
//@param int SIZE: 每个间隔大小
//ret: void
void BoardActions::FallByOne(int**& cheeseboard, vector<vector<Button*>>& Cheeses, int row, int col, double SIZE)
{
    //必须上下都有才能交换
    if (board[row + 1][col] > 0 && board[row][col] > 0)
    {
        //交换数字棋盘位置后
        int temp;
        temp = board[row + 1][col];
        board[row + 1][col] = board[row][col];
        board[row][col] = temp;
        //交换对象棋盘位置
        swap(cheeses.at(row).at(col), cheeses.at(row + 1).at(col));
        //坐标变化
        cheeses.at(row + 1).at(col)->setPos(cheeses.at(row + 1).at(col)->getPosX(), cheeses.at(row + 1).at(col)->getPosX() + SIZE);
        cheeses.at(row).at(col)->setPos(cheeses.at(row).at(col)->getPosX(), cheeses.at(row + 1).at(col)->getPosX() - SIZE);
    }
}

//向上位移，下面个棋子和上面个交换
//@param int** &chessboard: 数字棋盘，每个数字代表棋子种类
//@param vector<vector<QLabel*>> &Cheeses: 对象棋盘，二维向量，存储QLabel对象
//@param int rows: 行数
//@param int cols: 列数
//@param int SIZE: 每个间隔大小
//ret: void
void BoardActions::UperByOne(int**& cheeseboard, vector<vector<Button*>>& Cheeses, int row, int col, double SIZE)
{
    //必须上下都有才能交换
    if (board[row - 1][col] > 0 && board[row][col] > 0)
    {
        //交换数字棋盘位置后
        int temp;
        temp = board[row][col];
        board[row][col] = board[row - 1][col];
        board[row - 1][col] = temp;
        //交换对象棋盘位置
        swap(cheeses.at(row - 1).at(col), cheeses.at(row).at(col));
        //坐标交换
        cheeses.at(row - 1).at(col)->setPos(cheeses.at(row - 1).at(col)->getPosX(), cheeses.at(row + 1).at(col)->getPosX() - SIZE);
        cheeses.at(row).at(col)->setPos(cheeses.at(row).at(col)->getPosX(), cheeses.at(row + 1).at(col)->getPosX() + SIZE);
    }
}

//向左位移，下面个棋子和上面个交换
//@param int** &chessboard: 数字棋盘，每个数字代表棋子种类
//@param vector<vector<QLabel*>> &Cheeses: 对象棋盘，二维向量，存储QLabel对象
//@param int rows: 行数
//@param int cols: 列数
//@param int SIZE: 每个间隔大小
//ret: void
void BoardActions::LeftByOne(int**& cheeseboard, vector<vector<Button*>>& Cheeses, int row, int col, double SIZE)
{
    //必须上下都有才能交换
    if (board[row][col] > 0 && board[row][col - 1] > 0)
    {
        //交换数字棋盘位置后
        int temp;
        temp = board[row][col];
        board[row][col] = board[row][col - 1];
        board[row][col - 1] = temp;
        //交换对象棋盘位置
        swap(cheeses.at(row).at(col), cheeses.at(row).at(col - 1));
        //坐标交换
        cheeses.at(row).at(col - 1)->setPos(cheeses.at(row).at(col - 1)->getPosX() - SIZE, cheeses.at(row).at(col)->getPosY());
        cheeses.at(row).at(col)->setPos(cheeses.at(row).at(col)->getPosX() + SIZE, cheeses.at(row).at(col)->getPosY());
    }
}

//向右位移，下面个棋子和上面个交换
//@param int** &chessboard: 数字棋盘，每个数字代表棋子种类
//@param vector<vector<QLabel*>> &Cheeses: 对象棋盘，二维向量，存储QLabel对象
//@param int rows: 行数
//@param int cols: 列数
//@param int SIZE: 每个间隔大小
//ret: void
void BoardActions::RightByOne(int**& cheeseboard, vector<vector<Button*>>& Cheeses, int row, int col, double SIZE)
{
    //必须上下都有才能交换
    if (board[row][col] > 0 && board[row][col + 1] > 0)
    {
        //交换数字棋盘位置后
        int temp;
        temp = board[row][col];
        board[row][col] = board[row][col + 1];
        board[row][col + 1] = temp;
        //交换对象棋盘位置
        swap(cheeses.at(row).at(col), cheeses.at(row).at(col + 1));
        //y坐标交换
        cheeses.at(row).at(col + 1)->setPos(cheeses.at(row).at(col - 1)->getPosX() + SIZE, cheeses.at(row).at(col)->getPosY());
        cheeses.at(row).at(col)->setPos(cheeses.at(row).at(col)->getPosX() - SIZE, cheeses.at(row).at(col)->getPosY());
    }
}

//自由落体，直到有棋子
//@param int** &chessboard: 数字棋盘，每个数字代表棋子种类
//@param vector<vector<QLabel*>> &Cheeses: 对象棋盘，二维向量，存储QLabel对象
//@param int rows: 行数
//@param int cols: 列数
//@param int SIZE: 每个间隔大小
//ret: void
void BoardActions::GraviticallyFall(int row, int col)
{
    //越界退出
    if (row < 0 || row > cheeses.size() - 1 || col < 0 || col > cheeses.size())
    {
        return;
    }
    //数出一个棋子下面有几个空格，存入count
    int count = 0;
    for (int i = row + 1; i < cheeses.size(); i++)
    {
        if (board[i][col] == 0)
            count++;
    }
    if (count > 0)
    { 
        if (!isInit)
        {
            ch->ToFallByN(cheeses[row][col], count, 0);
            ch->ToUPByN(cheeses[row + count][col], count, 0);
        }
        else
        {
            Point p = cheeses[row][col]->getPos();
            cheeses[row][col]->setPos(cheeses[row + count][col]->getPos());
            cheeses[row + count][col]->setPos(p);
        }
        //交换数字棋盘位置
        int temp;
        temp = board[row + count][col];
        board[row + count][col] = board[row][col];
        board[row][col] = temp;

        swap(cheeses[row][col], cheeses[row + count][col]);
        
    }
}



//随机生成棋盘
//@param int** &chessboard: 数字棋盘，每个数字代表棋子种类
//@param int** &comp: 棋盘中间量
//@param vector<vector<QLabel*>> &Cheeses: 对象棋盘，二维向量，存储QLabel对象
//@param int SIZE: 每个间隔大小
//ret: void
void BoardActions::randomCreate()
{
    for (int i = 0; i < cheeses.size(); i++)
    {
        for (int j = 0; j < cheeses.size() + 1; j++)
        {
            board[i][j] = 0;
        }
    }
    padding();
    refreshBoard();
    //直到没有产生消除后退出循环
    //delete_(chessboard, comp, Cheeses, SIZE);
    while (delete_() > 0) {
        refreshBoard();
        padding();
        refreshBoard();

    }
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cheeses[i][j]->resetAction();

        }
    }
    isInit = false;
}

void BoardActions::reload(int** a)
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            board[i][j] = a[i][j];

        }
    }
    refreshBoard();
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cheeses[i][j]->resetAction();

        }
    }
    isInit = false;
}

//随机生成棋盘
//@param int** &chessboard: 数字棋盘，每个数字代表棋子种类
//@param int** &comp: 棋盘中间量
//@param vector<vector<QLabel*>> &Cheeses: 对象棋盘，二维向量，存储QLabel对象
//@param int SIZE: 每个间隔大小
//ret: int 1-发生了消除; 2-未发生消除
int BoardActions::delete_()
{
    int flag = 0;
    for (int i = 0; i < cheeses.size(); i++) {
        for (int j = 0; j < cheeses.size() + 1; j++) {
            //一旦有一个消除发生，则判定flag为1
            if (ScanAllAndDelete(i, j) > 0)
                flag = 1;
        }
    }
    for (int i = 0; i < cheeses.size(); i++) {
        for (int j = 0; j < cheeses.size() + 1; j++) {
            board[i][j] = comp[i][j];
            if (board[i][j] == 0)
            {
                //auto* q = gcnew null;
                //cheeses.at(i).at(j) = gcnew myButton(q);
            }
        }
    }
    //cout << "----------" << endl;
    
    FallAmongAll();
    //print(board, 7, 8);
    return flag;
}

//打印二维数组
//@param int** &chessboard: 数字棋盘，每个数字代表棋子种类
//@param int rows: 行数
//@param int cols: 列数
//ret: void
void BoardActions::print(int** matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

//根据数字棋盘刷新对象棋盘
//@param int** &chessboard: 数字棋盘，每个数字代表棋子种类
//@param vector<vector<Button *>>& Cheeses: 对象棋盘
//ret: void
void BoardActions::refreshBoard()
{
    //清空所有的棋子
    for (int i = 0; i < cheeses.size(); i++)
    {
        for (int j = 0; j < cheeses.size() + 1; j++)
        {
            vector<Node* > vec = sc->getChildren(to_wstring(i) + to_wstring(j));
            sc->removeChild(vec.at(0));
        }
    }
    for (int i = 0; i < cheeses.size(); i++)
    {
        cheeses.at(i).clear();
        for (int j = 0; j < cheeses.size() + 1; j++)
        {
            if (board[i][j] == 0)
            {
                auto* q = gcnew null;
                myButton* btn = gcnew myButton(q);
                btn->changeToNull();
                btn->setPos(LU_X + GAP * j, LU_Y + GAP * i);
                btn->setSize(IMAGE_LARGE, IMAGE_LARGE);
                //设置棋子名字方便检索
                btn->setName(to_wstring(i) + to_wstring(j));
                //btn->setClickFunc(std::bind(&Actions::Exchange, this));
                sc->addChild(btn);
                cheeses.at(i).push_back(btn);
            }
            if (board[i][j] == 1)
            {
                auto* q = gcnew Sword;
                myButton* btn = gcnew myButton(q);
                btn->changeToSword();
                btn->setPos(LU_X + GAP * j, LU_Y + GAP * i);
                btn->setSize(IMAGE_LARGE, IMAGE_LARGE);
                //设置棋子名字方便检索
                btn->setName(to_wstring(i) + to_wstring(j));
                sc->addChild(btn);
                cheeses.at(i).push_back(btn);
            }
            else if (board[i][j] == 2)
            {
                auto* q = gcnew Drug;
                myButton* btn = gcnew myButton(q);
                btn->changeToDrug();
                btn->setPos(LU_X + GAP * j, LU_Y + GAP * i);
                btn->setSize(IMAGE_LARGE, IMAGE_LARGE);
                //设置棋子名字方便检索
                btn->setName(to_wstring(i) + to_wstring(j));
                sc->addChild(btn);
                cheeses.at(i).push_back(btn);
            }
            else if (board[i][j] == 3)
            {
                auto* q = gcnew Anger;
                myButton* btn = gcnew myButton(q);
                btn->changeToAnger();
                btn->setPos(LU_X + GAP * j, LU_Y + GAP * i);
                btn->setSize(IMAGE_LARGE, IMAGE_LARGE);
                //设置棋子名字方便检索
                btn->setName(to_wstring(i) + to_wstring(j));
                sc->addChild(btn);
                cheeses.at(i).push_back(btn);
            }
        }
    }
    
}

//获取当前对象棋盘
//ret: vector<vector<Button*>> 对象棋盘
vector<vector<myButton*>> BoardActions::getCheese()
{
    return cheeses;
}

//获取当前数字棋盘
//@param int**& to: 拷贝去的棋盘
//ret: void
int** BoardActions::copyBoard()
{
    return board;
}

//获取这一轮的总攻击,并置0
//ret: int 总攻击
int BoardActions::getTotalAttack()
{
    int temp = totalAttack;
    totalAttack = 0;
    return temp;
}

//获取这一轮的总回复量,并置0
//ret: int 总回复量
int BoardActions::getTotalRecover()
{
    int temp = totalRecover;
    totalRecover = 0;
    return temp;
}

//获取这一轮的总怒气值,并置0
//ret: int 总怒气值
int BoardActions::getTotalAnger()
{
    int temp = totalAnger;
    totalAnger = 0;
    return temp;
}

void BoardActions::setSelected(int i, int j)
{
    cheeses[i][j]->setSelected2();
}

void BoardActions::setUnSelected(int i, int j)
{
    cheeses[i][j]->setUnSelected2();
}

void BoardActions::changeV(int s_i, int s_j, int e_i, int e_j)
{
    if (board[e_i][e_j] == 0)
        return;
    if (s_i < e_i)
    {
        ch->ToUperByOne(cheeses[e_i][e_j]);
        ch->ToFallByOne(cheeses[s_i][s_j]);
    }
    else
    {
        ch->ToUperByOne(cheeses[s_i][s_j]);
        ch->ToFallByOne(cheeses[e_i][e_j]);
    }
    int temp = board[s_i][s_j];
    board[s_i][s_j] = board[e_i][e_j];
    board[e_i][e_j] = temp;
    swap(cheeses[s_i][s_j], cheeses[e_i][e_j]);
}

void BoardActions::changeH(int s_i, int s_j, int e_i, int e_j)
{
    if (board[e_i][e_j] == 0)
        return;
    if (s_j < e_j)
    {
        ch->ToLeftByOne(cheeses[e_i][e_j]);
        ch->ToRightByOne(cheeses[s_i][s_j]);
    }
    else
    {
        ch->ToLeftByOne(cheeses[s_i][s_j]);
        ch->ToRightByOne(cheeses[e_i][e_j]);
    }
    int temp = board[s_i][s_j];
    board[s_i][s_j] = board[e_i][e_j];
    board[e_i][e_j] = temp;
    swap(cheeses[s_i][s_j], cheeses[e_i][e_j]);
}


//每个棋子重置动作
void BoardActions::releaseAllAction()
{
    for (int i = 0; i < 1; i++)
    {
        for (int j = 0; j < 1; j++)
        {
            cout << "i:  " << j << endl;
            cheeses[i][j]->run();
            cheeses[i][j]->resetAction();
        }
    }
}

//判断那些棋子可以进行三消，进行闪烁提示
void BoardActions::showTip()
{
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 1][j + 2])
            {
                ch->shine(cheeses[i][j]);
                ch->shine(cheeses[i + 1][j + 1]);
                ch->shine(cheeses[i + 1][j + 2]); 
                return;
            }
            if (board[i][j] == board[i][j + 1] && board[i][j + 1] == board[i + 1][j + 2])
            {
                ch->shine(cheeses[i][j]);
                ch->shine(cheeses[i][j + 1]);
                ch->shine(cheeses[i + 1][j + 2]);
                return;
            }
            if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i][j + 2])
            {
                ch->shine(cheeses[i][j]);
                ch->shine(cheeses[i + 1][j + 1]);
                ch->shine(cheeses[i][j + 2]);
                return;
            }
            if (board[i][j] == board[i + 1][j + 1] && board[i + 1][j + 1] == board[i + 2][j])
            {
                ch->shine(cheeses[i][j]);
                ch->shine(cheeses[i + 1][j + 1]);
                ch->shine(cheeses[i + 2][j]);
                return;
            }
            if (board[i][j] == board[i + 1][j + 1]&& board[i + 1][j + 1] == board[i + 2][j + 1])
            {
                ch->shine(cheeses[i][j]);
                ch->shine(cheeses[i + 1][j + 1]);
                ch->shine(cheeses[i + 1][j + 1]);
                return;
            }
            if (board[i][j] == board[i + 1][j] && board[i + 1][j] == board[i + 2][j + 1])
            {
                ch->shine(cheeses[i][j]);
                ch->shine(cheeses[i + 1][j]);
                ch->shine(cheeses[i + 2][j + 1]);
                return;
            }
           
            if (i > 0 && j > 0)
            {
                if (board[i][j] == board[i - 1][j + 1] && board[i - 1][j + 1] == board[i - 1][j + 2])
                {
                    ch->shine(cheeses[i][j]);
                    ch->shine(cheeses[i - 1][j + 1]);
                    ch->shine(cheeses[i - 1][j + 2]);
                    return;
                }
                if (board[i][j] == board[i][j + 1]&& board[i][j + 1] == board[i - 1][j + 2])
                {
                    ch->shine(cheeses[i][j]);
                    ch->shine(cheeses[i][j + 1]);
                    ch->shine(cheeses[i - 1][j + 2]);
                    return;
                }
                if (board[i][j] == board[i - 1][j + 1] && board[i - 1][j + 1] == board[i][j + 2])
                {
                    ch->shine(cheeses[i][j]);
                    ch->shine(cheeses[i - 1][j + 1]);
                    ch->shine(cheeses[i][j + 2]);
                    return;
                }
                if (board[i][j] == board[i + 1][j - 1] && board[i + 1][j - 1] == board[i + 2][j])
                {
                    ch->shine(cheeses[i][j]);
                    ch->shine(cheeses[i + 1][j - 1]);
                    ch->shine(cheeses[i + 2][j]);
                    return;
                }
                if (board[i][j] == board[i + 1][j - 1] && board[i + 1][j - 1] == board[i + 2][j - 1])
                {
                    ch->shine(cheeses[i][j]);
                    ch->shine(cheeses[i + 1][j - 1]);
                    ch->shine(cheeses[i + 1][j - 1]);
                    return;
                }
                if (board[i][j] == board[i + 1][j] && board[i + 1][j]==board[i + 2][j - 1])
                {
                    ch->shine(cheeses[i][j]);
                    ch->shine(cheeses[i + 1][j]);
                    ch->shine(cheeses[i + 2][j - 1]);
                    return;
                } 
            }
            cout << "none" << endl;
        }
    }
}

//获取三消，四消，五消和超级消除次数
vector<int> BoardActions::getCounts()
{
    vector<int> v;
    v.push_back(three / 9);
    v.push_back(four / 12);
    v.push_back(five / 15);
    v.push_back(diamond / 15);
    return v;
}

// ********************************************************************** //
//构造函数
//@param Player *playe: 玩家类
//@param monster *mo: 怪物类 
ActorActions::ActorActions(Player *playe, monster *mo)
{
    player = playe;
    mon = mo;
}

//析构函数
ActorActions::~ActorActions()
{
    delete player;
    delete mon;
}

//构造函数
//@param Player *playe: 玩家类
//@param monster *mo: 怪物类 
bool ActorActions::attackPlayer(int val)
{
    return player->receiveAttack(val);
}

//攻击怪物
//@param int val: 需要造成的伤害
//ret: bool 是否击败怪物
bool ActorActions::attackMonster(int val)
{
    return mon->receiveAttack(val);
}

//玩家血量回复
//@param int val: 需要造成的回复量
//ret: void
void ActorActions::recoverPlayer(float val)
{
    player->receiveRecover(val);
}

//玩家怒气值积累
//@param int val: 需要造成的怒气值积累
//ret: void
void ActorActions::angerPlayer(int val)
{
    player->receiveAnger(val);
    cout << "ee" << endl;
}

//怪物抖动效果
//ret: void
void ActorActions::shakeMonster()
{
    auto moveTo = gcnew MoveTo(0.01f, Point(mon->getPosX()+5, mon->getPosY()));
    auto moveTo2 = gcnew MoveTo(0.01f, Point(mon->getPosX() - 5, mon->getPosY()));
    auto moveTo3 = gcnew MoveTo(0.01f, Point(mon->getPosX(), mon->getPosY()));
    auto sequence = gcnew Sequence({ moveTo, moveTo2, moveTo3 });
    auto loop = gcnew Loop(sequence, 5);
    mon->runAction(loop);
}