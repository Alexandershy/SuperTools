mkdir SuperTools-Github
mkdir SuperTools-Github/build-SuperTools-linux-Desktop_Qt_6_3_0_GCC_64bit
mkdir SuperTools-Github/build-SuperTools-linux-Desktop_Qt_6_3_0_GCC_64bit/release
mkdir SuperTools-Github/build-SuperTools-linux-Desktop_Qt_6_3_0_GCC_64bit/release/__plugins__
cp -r SuperTools-Build/build-_supertools_-Desktop_Qt_6_3_0_GCC_64bit/release/ SuperTools-Github/build-SuperTools-linux-Desktop_Qt_6_3_0_GCC_64bit/
rm SuperTools-Github/build-SuperTools-linux-Desktop_Qt_6_3_0_GCC_64bit/release/*.h
rm SuperTools-Github/build-SuperTools-linux-Desktop_Qt_6_3_0_GCC_64bit/release/*.o
rm SuperTools-Github/build-SuperTools-linux-Desktop_Qt_6_3_0_GCC_64bit/release/*.cpp
rm -r SuperTools-Github/build-SuperTools-linux-Desktop_Qt_6_3_0_GCC_64bit/release/__htmllibary__
rm -r SuperTools-Github/build-SuperTools-linux-Desktop_Qt_6_3_0_GCC_64bit/release/__depycache__
rm -r SuperTools-Github/build-SuperTools-linux-Desktop_Qt_6_3_0_GCC_64bit/release/__readme__
