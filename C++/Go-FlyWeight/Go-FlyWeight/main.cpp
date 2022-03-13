//
//  main.cpp
//  Go-FlyWeight
//
//  Created by MTX on 2022/3/12.
//
//  向量（Vector）是一个封装了动态大小数组的顺序容器（Sequence Container）可以认为是一个动态数组的抽象，其中一个vector中的所有对象都必须是同一种类型

#include <iostream>
#include <vector>
#include <string>
using namespace std;

enum PieceColor {BLACK, WHITE};//棋子颜色
class PiecePos {//棋子位置
private:
    int x;
    int y;
public:
    PiecePos(int a, int b): x(a), y(b) {}
    int getX() { return x; }
    int getY() { return y; }
};
class Piece {//棋子定义
protected:
    PieceColor m_color;//颜色
    PiecePos m_pos;//位置
public:
    Piece(PieceColor color, PiecePos pos): m_color(color), m_pos(pos) {}
    virtual void Draw() {}
    string description() {//描述棋子的颜色和位置
        const char *color = (m_color==BLACK)?"black":"white";
        int x = m_pos.getX();
        int y = m_pos.getY();
        char *buf = new char[100];//避免数组越界 malloc: Incorrect checksum for freed object
        sprintf(buf, "color:%s, position:(%d,%d)", color, x, y);
        return buf;
    }
};
class BlackPiece: public Piece {
public:
    BlackPiece(PieceColor color, PiecePos pos): Piece(color, pos){}
    void Draw() {cout << "draw a black piece" << endl;}
};
class WhitePiece: public Piece {
public:
    WhitePiece(PieceColor color, PiecePos pos): Piece(color, pos){}
    void Draw() {cout << "draw a white piece" << endl;}
};
class PieceBoard {
private:
    vector<Piece*> m_vecPiece;//棋盘上已有的棋子
    string m_blackName;//黑方名称
    string m_whiteName;//白方名称
public:
    PieceBoard(string black, string white): m_blackName(black), m_whiteName(white){}
    void setPiece(PieceColor color, PiecePos pos) {//一步棋，在棋盘上放一颗棋子
        Piece* piece = NULL;
        if (color == BLACK) {//放黑子
            piece = new BlackPiece(color, pos);
            cout << m_blackName << "在位置（" << pos.getX() << "," << pos.getY() << "）";
            piece->Draw();
        }
        else {//放白子
            piece = new WhitePiece(color, pos);
            cout << m_whiteName << "在位置（" << pos.getX() << "," << pos.getY() << "）";
            piece->Draw();
        }
        m_vecPiece.push_back(piece);
    }
    vector<Piece*> getAllPieces() {
        cout << "棋盘上所有的棋子(" << m_vecPiece.size() << "):" << endl;
        /*
         for(语句1;语句2;语句3) {}
         语句 1 在循环（代码块）开始前执行
         语句 2 定义运行循环（代码块）的条件
         语句 3 在循环（代码块）已被执行之后执行
         这就是循环中的 ++i 和 i++ 结果一样的原因，但是性能不一样，在大量数据的时候 ++i 的性能要比 i++ 的性能好原因:
         i++ 由于是在使用当前值之后 再+1 ，所以需要一个临时的变量来转存。 而 ++i 则是在直接 +1 ，省去了对内存的操作的环节，相对而言能够提高性能。
         */
        for(int i = 0;i < m_vecPiece.size();++i) {
            Piece* p = m_vecPiece[i];
            cout << "[" << i << "] " << p->description() << endl;//指针获取对象的成员函数可以使用 -> 操作符
        }
        cout << "========" << endl;
        for(vector<Piece*>::iterator item=m_vecPiece.begin();item<m_vecPiece.end();++item){//迭代器遍历
            Piece* p = *item;
            cout << p->description() << endl;//指针获取对象的成员函数可以使用 -> 操作符
        }
        return m_vecPiece;
    }
};

int main(int argc, const char * argv[]) {
    PieceBoard board = PieceBoard("blackPlayer", "whitePlayer");
    board.setPiece(BLACK, PiecePos(2, 3));
    board.setPiece(WHITE, PiecePos(3, 3));
    board.getAllPieces();
    return 0;
}
