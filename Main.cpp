#include "LC146.cpp"

struct input {
    int key;
    int val;
};

std::unique_ptr<LRUCache> lRUCache_ptr{};
std::map<std::string, std::function<string(const input&)> > name_func_map{
    {"LRUCache",
     [](const input& i) {
         lRUCache_ptr.reset(new LRUCache(i.key));
         return string("null");
     }},
    {"put",
     [](const input& i) {
         lRUCache_ptr->put(i.key, i.val);
         return string("null");
     }},
    {"get",
     [](const input& i) { return std::to_string(lRUCache_ptr->get(i.key)); }}};

int main() {
    std::vector<std::string> name_vec{"LRUCache", "put", "put", "put", "put",
                                      "get",      "get", "get", "get", "put",
                                      "get",      "get", "get", "get", "get"};
    std::vector<input> input_vec{{{3},
                                  {1, 1},
                                  {2, 2},
                                  {3, 3},
                                  {4, 4},
                                  {4},
                                  {3},
                                  {2},
                                  {1},
                                  {5, 5},
                                  {1},
                                  {2},
                                  {3},
                                  {4},
                                  {5}}};
    std::vector<std::string> ans_vec{"null", "null", "null", "null", "null",
                                     "4",    "3",    "2",    "-1",   "null",
                                     "-1",   "2",    "3",    "-1",   "5"};

    for (int i = 0; i < name_vec.size(); ++i) {
        std::cout << std ::format("i={}, name={}, input={{{}, {}}}, ans_vec={}",
                                  i, name_vec[i], input_vec[i].key,
                                  input_vec[i].val, ans_vec[i]);
        auto&& ans = name_func_map[name_vec[i]](input_vec[i]);
        std::cout << std ::format(", ans={}\n", ans);
    }
    return 0;
}
