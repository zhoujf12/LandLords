#ifndef CARDPANEL_H
#define CARDPANEL_H

#include <QWidget>
#include <QMouseEvent>
#include"card.h"
#include"player.h"
class CardPanel : public QWidget
{
    Q_OBJECT
public:
    explicit CardPanel(QWidget *parent = nullptr);

    //设置图片的函数,QPixmap类用于加载图片，显示图片内容
    //front正面，back背面
    void setImage(QPixmap &front,QPixmap &back);
    //获取图片
    QPixmap getImage();

    //扑克牌显示哪一面
    void setFrontSide(bool flag);
    bool isFrontSide();

    //记录窗口是否被选中
    void setSelected(bool flag);
    bool isSelected();

    //扑克牌的花色以及点数
    void setCard(Card &card);
    Card getCard();

    //扑克牌的所有者
    void setOwner(Player* player);
    Player*getOwner();

    //模拟扑克牌的点击事件
    void clicked();

protected:
    //事件处理函数，将一张图片绘制到当前窗口
    void paintEvent(QPaintEvent *event);
    //鼠标点击事件
    void mousePressEvent(QMouseEvent *event);
signals:
    void cardSelected(Qt::MouseButton button);

private:
    QPixmap m_front;
    QPixmap m_back;
    bool m_isfront;//判断窗口是正面还是背面
    bool m_isSelect;//判断窗口是否被选中
    Card m_card;
    Player* m_owner;
};

#endif // CARDPANEL_H
