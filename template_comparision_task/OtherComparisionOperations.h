#pragma once

template<typename T>
class OtherComparisionOperators {
public:
    template<typename Compare>
    bool operator<=(Compare other) const {
        return !(derived() > other);
    }

    template<typename Compare>
    bool operator>=(Compare other) const {
        return !(derived() < other);
    }

    template<typename Compare>
    bool operator==(Compare other) const {
        return derived() <= other && derived() >= other;
    }

    template<typename Compare>
    bool operator!=(Compare other) const {
        return !(derived() == other);
    }
private:
    const T& derived() const noexcept { return static_cast<const T&>(*this); }
};