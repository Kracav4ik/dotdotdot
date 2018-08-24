#include <iostream>
#include <vector>
#include <list>
#include <tuple>

namespace ns {
    template <typename T>
    void print_ip(T t);

    template <typename T>
    void outListSame(const T& t) {
        bool flag = false;
        for (int item : t) {
            if (flag) {
                std::cout << '.';
            }
            flag = true;
            std::cout << item;
        }

        std::cout << std::endl;
    }

    template <typename T>
    void outIp(T res) {
        std::vector<T> v;
        for (int i = 0; i < sizeof(T); ++i) {
            v.insert(v.begin(), res % 0x100);
            res /= 0x100;
        }
        outListSame<>(v);
    }

    template <>
    void print_ip<char>(char t) {
        outIp<>(static_cast<uint8_t>(t));
    }

    template <>
    void print_ip<short>(short t) {
        outIp<>(static_cast<uint16_t>(t));
    }

    template <>
    void print_ip<int>(int t) {
        outIp<>(static_cast<uint32_t>(t));
    }

    template <>
    void print_ip<long>(long t) {
        outIp<>(static_cast<uint64_t>(t));
    }

    template <>
    void print_ip<std::string>(std::string t) {
        std::cout << t << std::endl;
    }

    template <>
    void print_ip<std::vector<int>>(std::vector<int> t) {
        outListSame<>(t);
    }

    template <>
    void print_ip<std::list<int>>(std::list<int> t) {
        outListSame<>(t);
    }

    template <>
    void print_ip<std::tuple<int, int, int, int>>(std::tuple<int, int, int, int> t) {
        std::cout << std::get<0>(t) << '.' << std::get<1>(t) << '.' << std::get<2>(t) << '.' << std::get<3>(t) << std::endl;
    }
}

int main() {
    ns::print_ip(char(-1));
    ns::print_ip(short(0));
    ns::print_ip(int(2130706433));
    ns::print_ip(long(8875824491850138409));
    ns::print_ip(std::string("10.0.0.0"));
    ns::print_ip(std::vector<int>({1, 178, 0, 255}));
    ns::print_ip(std::list<int>({128, 168, 0, 255}));
    ns::print_ip(std::make_tuple(55, 40, 60, 65));
    return 0;
}