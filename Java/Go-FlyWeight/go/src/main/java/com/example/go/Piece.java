package com.example.go;

import java.util.*;
enum PieceColor{BLACK,WHITE}//棋子颜色
class PiecePos{//棋子位置
    private int x;
    private int y;
    public PiecePos(int a,int b){x=a;y=b;}
    public int getX(){return x;}
    public int getY(){return y;}
}
abstract class Piece {//棋子定义
    protected PieceColor m_color;//颜色
    protected PiecePos m_pos;//位置
    public Piece(PieceColor color, PiecePos pos){m_color=color;m_pos=pos;}
    //指向基类的指针在操作它的多态类对象时，会根据不同的类对象，调用其相应的函数，这个函数就是虚函数。C++ 中必须用 virtual 修饰。
    //java的普通成员函数（没有被static、native、final等关键字修饰）就是虚函数，原因很简单，它本身就实现虚函数实现的功能-多态。
    //从字节码指令的命名上也可以看出，java中的普通成员函数就是虚函数。
    void draw(){}
}
class BlackPiece extends Piece {//黑棋
    public BlackPiece(PieceColor color, PiecePos pos) {super(color, pos);}
    public void draw() {
        System.out.println("draw a black piece.");
    }
}
class WhitePiece extends Piece {//白棋
    public WhitePiece(PieceColor color, PiecePos pos) {super(color, pos);}
    public void draw() {
        System.out.println("draw a white piece.");
    }
}
class PieceBoard{//棋盘上已有的棋子
    private static final ArrayList<Piece> m_arrayPiece=new ArrayList();
    private String m_blackName;//黑方名称
    private String m_whiteName;//白方名称
    public PieceBoard(String black,String white){m_blackName=black;m_whiteName=white;}
    //一步棋,在棋盘上放一颗棋子
    public void SetPiece(PieceColor color,PiecePos pos) {
        Piece piece = null;
        if (color == PieceColor.BLACK) {//放黑子
            piece = new BlackPiece(color, pos);//获取一颗黑子
            System.out.print(m_blackName + " 在位置（" + pos.getX() + "," + pos.getY() + ") ");
            piece.draw();
        } else {//放白子
            piece = new WhitePiece(color, pos);//获取一颗白子
            System.out.print(m_whiteName + " 在位置（" + pos.getX() + "," + pos.getY() + ") ");
            piece.draw();
        }
        m_arrayPiece.add(piece);
    }
}
class go{//围棋的英文为go
    public static void main(String[] args){
        //System.out.println("Hello World!");
        PieceBoard board=new PieceBoard("blackPlayer", "whitePlayer");
        BlackPiece black=new BlackPiece(PieceColor.BLACK, new PiecePos(1,2));
        board.SetPiece(PieceColor.BLACK, new PiecePos(2,3));
        board.SetPiece(PieceColor.WHITE, new PiecePos(3,3));
    }
}