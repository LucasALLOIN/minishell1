#!/bin/bash

echo "Basic test"
printf "Testing ls: "
echo "ls --color=auto" | ../mysh | sed -e "s/$>//g" | cat -e > d1
echo "ls --color=auto" | sh | sed -e "s/$>//g" | cat -e > d2
diff=$(diff d1 d2)

if [ "$diff" == "" ]
then
    echo -e "\e[32mOK\e[0m"
else
    echo -e "\e[31mFailed\e[0m"
fi

printf "Testing env: "
echo "env" | ../mysh | sed -e "s/$>//g" | sed -e "s/_=..\/mysh//g" | cat -e > d1
echo "env" | sh | sed -e "s/$>//g" | sed -e "s/_=..\/mysh//g" | cat -e > d2
diff=$(diff d1 d2)

if [ "$diff" == "" ]
then
    echo -e "\e[32mOK\e[0m"
else
    echo -e "\e[31mFailed\e[0m"
fi
