rm -rf build
mkdir build && cd build
cmake ../
make
sudo chmod +x Pong
sudo mv Pong /usr/bin
