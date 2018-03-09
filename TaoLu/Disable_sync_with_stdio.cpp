static auto disable_sync_stdio = []() {
    return std::ios::sync_with_stdio(false);
}();