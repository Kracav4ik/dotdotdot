#include <iostream>
#include <vector>
#include <list>
#include <tuple>

namespace ns {
    //! Writes ip in output.
    //! \tparam T Ip type (char, short, int, long, std::string, std::vector<int>, std::list<int>, std::tuple<int, int, int, int>).
    //! \param t Ip value.
    template <typename T>
    void print_ip(T t);

    //! Writes ip in output if type like list.
    //! \tparam T Ip type (std::string, std::vector<int>, std::list<int>)
    //! \param t Ip value
    template <typename T>
    void outLikeList(const T& t) {
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

    //! Writes ip in output if type like int.
    //! \tparam T Ip type (char, short, int, long)
    //! \param t Ip value
    template <typename T>
    void outIp(T res) {
        std::vector<T> v;
        for (int i = 0; i < sizeof(T); ++i) {
            v.insert(v.begin(), res % 0x100);
            res /= 0x100;
        }
        outLikeList<>(v);
    }

    //! Calls outIp with type is uint8_t.
    template <>
    void print_ip<char>(char t) {
        outIp<>(static_cast<uint8_t>(t));
    }

    //! Calls outIp with type is uint16_t.
    template <>
    void print_ip<short>(short t) {
        outIp<>(static_cast<uint16_t>(t));
    }

    //! Calls outIp with type is uint32_t.
    template <>
    void print_ip<int>(int t) {
        outIp<>(static_cast<uint32_t>(t));
    }

    //! Calls outIp with type is uint64_t.
    template <>
    void print_ip<long>(long t) {
        outIp<>(static_cast<uint64_t>(t));
    }

    //! Writes a string in output.
    template <>
    void print_ip<std::string>(std::string t) {
        std::cout << t << std::endl;
    }

    //! Calls outLikeList with type is std::vector<int>.
    template <>
    void print_ip<std::vector<int>>(std::vector<int> t) {
        outLikeList<>(t);
    }

    //! Calls outLikeList with type is std::list<int>.
    template <>
    void print_ip<std::list<int>>(std::list<int> t) {
        outLikeList<>(t);
    }

    //! Writes a std::tuple<int, int, int, int> in output.
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