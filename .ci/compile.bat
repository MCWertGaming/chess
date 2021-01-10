git reset --hard
git clean -fdx
cmake --build . --config Release

git reset --hard
git clean -fdx
cmake --build . --config Debug
