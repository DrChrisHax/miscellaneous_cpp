#include "OrderBook.h"

OrderBookLevelInfos::OrderBookLevelInfos(const LevelInfos& bids, const LevelInfos asks)
    : bids_{bids}
    , asks_{asks}
{
    
}