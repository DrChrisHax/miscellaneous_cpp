#ifndef ORDER_BOOK_H_
#define ORDER_BOOK_H_

// This is adapted from Coding Jesus's videos
// They can be found below
// https://www.youtube.com/watch?v=XeLWe0Cx_Lg

#include <cstdint>
#include <vector>
#include <exception>
#include <string>
#include <format>

enum class OrderType {
    GoodTillCancel,
    FillAndKill
};

enum class Side {
    Buy,
    Sell
};

using Price = int32_t;
using Quantity = uint32_t;
using OrderID = uint64_t;

struct LevelInfo {
    Price price;
    Quantity quantity;
};

using LevelInfos = std::vector<LevelInfo>;

class OrderBookLevelInfos {
public:
    OrderBookLevelInfos(const LevelInfos& bids, const LevelInfos asks)
        : bids_{bids}
        , asks_{asks}
    {}

    const LevelInfos& GetBids() const { return bids_; }
    const LevelInfos& GetAsks() const { return asks_; }

private:
    LevelInfos bids_;
    LevelInfos asks_;
};

class Order {
public:
    Order(OrderType orderType, OrderID orderID, Side side, Price price, Quantity quantity) 
        : orderType_{orderType}
        , orderID_{orderID}
        , side_{side}
        , price_{price}
        , initialQuantity_{quantity}
        , remainingQuantity_{quantity}
    {}

    OrderType GetOrderType() const { return orderType_; }
    OrderID GetOrderID() const { return orderID_; }
    Side GetSide() const { return side_; }
    Price GetPrice() const { return price_; }
    Quantity GetInitialQuantity() const { return initialQuantity_; }
    Quantity GetRemainingQuantity() const { return remainingQuantity_; }
    Quantity GetFilledQuantity() const { return GetInitialQuantity() - GetRemainingQuantity(); }

    void Fill(Quantity quantity) {
        if (quantity > GetRemainingQuantity()) {
            throw std::logic_error(std::format("Order ({}) cannot be filled for more than its remaining quantity.", GetOrderID()));
        }
    }

private:
    OrderType orderType_;
    OrderID orderID_;
    Side side_;
    Price price_;
    Quantity initialQuantity_;
    Quantity remainingQuantity_;
};




#endif // ORDER_BOOK_H_