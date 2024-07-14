 #ifndef CARDS_H
#define CARDS_H
#include"card.h"
#include<QSet>

class Cards
{
public:
    //升序，降序
    enum SortType{Asc,Desc,NoSort};
    Cards();
    Cards(const Card &card);
    //发牌
    void add(const Card& card);
    void add(const Cards& cards);//如果是地主，需要发三张地主牌
    void add(const QVector<Cards>& cards);


    //一次性插入多个数据，操作符<<重载
    Cards& operator <<(const Card& card);
    Cards& operator <<(const Cards& cards);

    //出牌
    void remove(const Card& card);
    void remove(const Cards& cards);
    void remove(const QVector<Cards> &cards);

    //扑克牌数量
    int cardCount();

    //玩家手里的牌是否为空
    bool isEmpty();

    //清空扑克牌
    void clear();

    //最大点数
    Card::CardPoint maxPoint();
    //最小点数
    Card::CardPoint minPoint();
    //指定点数的牌的数量
    int pointCount(Card::CardPoint point);
    //某张牌是否在集合中
    bool contains(const Card& card);
    bool contains(const Cards& cards);

    //随机取出一张牌
    Card takeRandCard();

    //QVector<Card>
    CardList toCardList(SortType type = Desc);
private:
    //在c++中，set容器自动排序，且不重复   在qt中set不重复，但无自动排序
    QSet<Card>m_cards;
};

#endif // CARDS_H
