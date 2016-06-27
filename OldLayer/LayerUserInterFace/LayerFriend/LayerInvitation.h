//
//  LayerInvitation.h
//  pokerclient
//
//  Created by ll on 15/8/21.
//
//

#ifndef __pokerclient__LayerInvitation__
#define __pokerclient__LayerInvitation__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "BaseLayer.h"
#include "cocos-ext.h"
#include "events.h"

#include "msg.pb.h"
#include "LayerManager.h"
using namespace cocos2d;
using namespace cocos2d::ui;
using namespace extension;

class LayerInvitation : public BaseLayer, public TableViewDataSource, public TableViewDelegate
{
public:
    
    CREATE_FUNC(LayerInvitation);
    virtual bool init();
    void onExit();
    void update_table_view(cmd_data_pointer data);
private:
    
    TableView* tableview_;
    events::event_dispatch dispatch_;
    
    void clickback(Ref * sender);
    
#pragma mark tableview datasource --
    virtual Size cellSizeForTable(TableView *table) {
        return Size(DESIGN_WIDTH, 121);
    };
    virtual TableViewCell* tableCellAtIndex(TableView *table, ssize_t idx);
    virtual ssize_t numberOfCellsInTableView(TableView *table);
#pragma mark tableview delegate --
    virtual void tableCellTouched(TableView* table, TableViewCell* cell);
    virtual void tableCellHighlight(TableView* table, TableViewCell* cell){};
    virtual void tableCellUnhighlight(TableView* table, TableViewCell* cell){};
    virtual void tableCellWillRecycle(TableView* table, TableViewCell* cell){};
    
    
private:
    std::vector<msg::Invitation> invitations_;

    std::function<void()> back_callback_;
};
#endif /* defined(__pokerclient__LayerInvitation__) */
