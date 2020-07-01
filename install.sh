#!/bin/bash





if [[ "$OSTYPE" == "linux-gnu"* ]]; then

    if [ $1 ]; then
        if [[ $1 == "libs" ]]; then
            echo "Fedora, Centos, ...   [1]"
            echo "Debian, Ubuntu, Popos [2]"
            read -p  "Choose you os. " os
            if [[ $os == "1" ]]; then
                echo -e "\e[31mSorry libs intallation are not implemented yet.\e[0m"
            elif [[ $os == "2" ]]; then
                echo -e "\e[31mSorry libs intallation are not implemented yet.\e[0m"
            else
                echo Please use 1 or 2.
            fi
        else
            echo -e "\e[31mBad arguments. in order to install libs use <libs>.\e[0m"
        fi
    fi
    echo -e "\e[93mCompiling your project...\e[0m"
    rm -rf .build;
    mkdir .build;
    cd .build;

    cmake ..;
    make;

    cd ..;

    echo -e "\e[92mYour project is ready.\e[0m"

elif [[ "$OSTYPE" == "win32" ]]; then
    #echo -e "\e[93mCompiling your project...\e[0m"
    #rd /s /q .build;
    #mkdir .build;
    #cd .build;

    #cmake ..;
    #cmake --build .;

    #cd ..;

    #rd /s /q .build;
    #move Debug\bomberman.exe .;
    #echo -e "\e[92mYour project is ready.\e[0m"
    echo -e "\e[31mnot working yet on windows. Come back soon!\e[0m"

elif [[ "$OSTYPE" == "msys" ]]; then
    #echo -e "\e[93mCompiling your project...\e[0m"
    #rd /s /q .build;
    #mkdir .build;
    # cd .build;

    #cmake ..;
    #cmake --build .;

    #cd ..;

    # rd /s /q .build;
    #move Debug\bomberman.exe .;
    # echo -e "\e[92mYour project is ready.\e[0m"
    echo -e "\e[31mnot working yet on windows. Come back soon!\e[0m"

elif [[ "$OSTYPE" == "darwin"* ]]; then
        echo -e "\e[31mnot working yet on OSX. Come back soon!\e[0m"
elif [[ "$OSTYPE" == "cygwin" ]]; then
        echo -e "\e[31mnot working yet on this os. Come back soon!\e[0m"
elif [[ "$OSTYPE" == "freebsd"* ]]; then
        echo -e "\e[31mnot working yet on freebsd. Come back soon!\e[0m"
else
        echo -e "\e[31munrecognized os.\e[0m"
fi