for f in $(find . -type f -not -path "*.git/*" -not -path "*build*"); do
    if [[ ${f} =~ \.(c|h|hpp|hh|cpp|cc)$ ]]; then
        clang-format -i ${f}
    fi
done
