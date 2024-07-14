#include "card.h"

Card::Card()
{

}

Card::Card(Card::CardPoint point, Card::CardSuit suit)
{
    setPoint(point);
    setSuit(suit);
}

void Card::setPoint(Card::CardPoint point)
{
    m_point= point;
}

void Card::setSuit(Card::CardSuit suit)
{
    m_suit = suit;
}

Card::CardPoint Card::getPoint()const
{
    return m_point;
}

Card::CardSuit Card::getSuit()const
{
    return m_suit;
}




bool lessSort(const Card &c1,const Card &c2)
{
    if(c1.getPoint()==c2.getPoint()){
        return c1.getSuit()<c2.getSuit();
    }
    else{
        return c1.getPoint()<c2.getPoint();
    }
}

bool greaterSort(const Card &c1,const Card &c2)
{
    if(c1.getPoint()==c2.getPoint()){
        return c1.getSuit()>c2.getSuit();
    }
    else{
        return c1.getPoint()>c2.getPoint();
    }
}

bool operator ==(const Card &left, const Card &right)
{
    return (left.getPoint()==right.getPoint()&&left.getSuit()==right.getSuit());
}

uint qHash(const Card &card)
{
    return card.getPoint()*100+card.getSuit();
}

bool operator<(const Card &left, const Card &right)
{
    return lessSort(left,right);
}
