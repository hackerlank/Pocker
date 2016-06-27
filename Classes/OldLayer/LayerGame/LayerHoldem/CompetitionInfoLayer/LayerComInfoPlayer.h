//
//  LayerComInfoPlayer.h
//  pokerclient
//
//  Created by ll on 15/11/26.
//
//

#ifndef __pokerclient__LayerComInfoPlayer__
#define __pokerclient__LayerComInfoPlayer__

#include "cocos2d.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "cocos-ext.h"
#include "events.h"
#include "utils.h"

#include "msg.pb.h"

#include "LayerComInfoTable.h"
#include "NodeComInfoPlayerCell.h"

using namespace cocos2d;
using namespace cocos2d::ui;
using namespace extension;

class LayerComInfoPlayer : public Layer, public TableViewDataSource, public TableViewDelegate, public EditBoxDelegate {
public:
    
    CREATE_FUNC(LayerComInfoPlayer);
    virtual bool init();
    
public:
    void update_data(const msg::Processor_530_PokerGetTourmentStatus_DOWN& tourment_status);

private:
    
    TableView* tableview_;
    events::event_dispatch dispatch_;
    
#pragma mark tableview datasource --
    virtual cocos2d::Size cellSizeForTable(TableView *table) {
        return cocos2d::Size(130, 68);
    };
    virtual TableViewCell* tableCellAtIndex(TableView *table, ssize_t idx);
    virtual ssize_t numberOfCellsInTableView(TableView *table);
#pragma mark tableview delegate --
    virtual void tableCellTouched(TableView* table, TableViewCell* cell);
    virtual void tableCellHighlight(TableView* table, TableViewCell* cell);
    virtual void tableCellUnhighlight(TableView* table, TableViewCell* cell);
    virtual void tableCellWillRecycle(TableView* table, TableViewCell* cell){};
    
#pragma mark editbox delegate --
    virtual void editBoxEditingDidBegin(EditBox* editBox);
    virtual void editBoxEditingDidEnd(EditBox* editBox);
    virtual void editBoxTextChanged(EditBox* editBox, const std::string& text);
    virtual void editBoxReturn(EditBox* editBox);
    
private:
    Node* root_;

    EditBox* tf_keyword_;
    uint32_t roomid;
    uint32_t select_table_id_;
    std::vector<std::shared_ptr<msg::TourmentTableInfo> > player_cell_datas_;
};

#endif /* defined(__pokerclient__LayerComInfoPlayer__) */
