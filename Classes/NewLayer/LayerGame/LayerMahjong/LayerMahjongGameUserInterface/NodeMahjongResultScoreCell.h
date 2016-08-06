//
//  NodeMahjongResultScoreCell.hpp
//  pokerclient
//
//  Created by zhongyu on 16/6/3.
//
//

#ifndef NodeMahjongResultScoreCell_hpp
#define NodeMahjongResultScoreCell_hpp

#include "SceneManager.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "cocos-ext.h"
#include "msg.pb.h"

using namespace cocos2d;
using namespace cocos2d::ui;
using namespace extension;

class NodeMahjongResultScoreCell : public TableViewCell
{
public:
    CREATE_FUNC(NodeMahjongResultScoreCell);
    virtual bool init();
private:
    Node* root_;
    Text* text_status_;
    Text* text_score_;
    Text* text_direction_;
#pragma mark value
    msg::MahjongScoreChange score_change_;
public:
    void set_data( msg::MahjongScoreChange score_change);
};


#endif /* NodeMahjongResultScoreCell_hpp */