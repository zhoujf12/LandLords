#ifndef CARD_H
#define CARD_H
#include <QVector>

class Card
{
public:

    //花色
    enum CardSuit
    {
        Suit_Begin,
        Diamond,//方块
        Club,//梅花
        Heart,//红桃
        Spade,//黑桃
        Suit_End
    };
    //点数
    enum CardPoint
    {
        Card_Begin,
        Card_3,
        Card_4,
        Card_5,
        Card_6,
        Card_7,
        Card_8,
        Card_9,
        Card_10,
        Card_J,
        Card_Q,
        Card_K,
        Card_A,
        Card_2,
        Card_SJ,//small joker 小王
        Card_BJ,//big joker  大王
        Card_End
    };
    Card();
    Card(CardPoint point,CardSuit suit);

    //提供set，get方法   以便外部访问到属性
    void setPoint(CardPoint point);
    void setSuit(CardSuit suit);
    CardPoint getPoint() const;
    CardSuit getSuit() const;

private:
    //将成员变量设置为私有，以确保外部无法随便访问
    CardSuit m_suit;
    CardPoint m_point;
};
//比较函数
bool lessSort(const Card& c1,const Card& c2);
bool greaterSort(const Card& c1,const Card& c2);

//操作符重载
bool operator ==(const Card& left,const Card& right);
bool operator<(const Card& left,const Card& right);


//重写全局函数
uint qHash(const Card &card);


//定义类型的别名
using CardList = QVector<Card>;

#endif // CARD_H
