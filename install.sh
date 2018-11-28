#!/bin/bash

USER=""
PASSWORD=""

if [[ $EUID -ne 0 ]]; then
    echo "Please run this script in root mode"
    exit 0
fi

function ask_logins()
{
    read -p "User(epitech e-mail) : " USER
    read -sp "Password : " PASSWORD
}

function ask_config()
{
    echo "Default config setup (leave empty for default):"
    read -p "git url (default : git@git.epitech.eu): " URL
    read -p "commit message (default : Saving Project): " MESSAGE
    read -p "permissions (default ramassage-tek r): " PERMS
    read -n1 -p "colors : (default : true) [t|f]: " COLORS
    if [ -z $URL ]
    then
        URL="git@git.epitech.eu"
    fi
    if [ -z $MESSAGE ]
    then
        MESSAGE="Saving Project"
    fi
    if [ -z $PERMS ]
    then
        PERMS="ramassage-tek r"
    fi
    if [ -z $COLORS ]
    then
        COLORS="true"
    fi
    if [ $COLORS == "f" ]
    then
        COLORS="false"
    elif [ $COLORS == "t" ]
    then
        COLORS="true"
    else
        COLORS="true"
    fi
}

clear
echo -e "Please enter your blih logins:\n"
ask_logins
while true; do
    clear
    echo -e "Are thoses logins correct ? [y|n]"
    echo "$USER | $PASSWORD"
    read -n1 yn
    case $yn in
        [Yy]* ) break;;
        "" ) break;;
        [Nn]* ) clear; ask_logins;;
        * ) echo "Please enter y or n";;
    esac
done
clear
ask_config
while true; do
    clear
    echo "Are you satisfied with those answers ? [y|n] (default yes):"
    echo "url : $URL"
    echo "message : $MESSAGE"
    echo "perms : $PERMS"
    echo "colors: $COLORS"
    read -n1 yn
    case $yn in
        [Yy]* ) break;;
        "" ) break;;
        [Nn]* ) clear; ask_config;;
        * ) echo "Please enter y or n";;
    esac
done
clear
echo "Creating config file"
echo "git_url:$URL" > .repo_config
echo "user:$USER" >> .repo_config
echo "default_commit_message:$MESSAGE" >> .repo_config
echo "default_perms:$PERMS" >> .repo_config
echo "colors:$COLORS" >> .repo_config
mv .repo_config ~/
echo "Config file created"
echo "Searching for blih file"
if [ -f "/usr/bin/blih" ]
then
    echo "Found /usr/bin/blih"
else
    echo "Blih file not found, stopping installation"
    exit 1
fi
grep -q "getpass.getuser()" /usr/bin/blih
OUT=$?
if [ $OUT -eq 1 ]
then
    echo "Could not find user section"
    exit 1
else
    sed -i "s/getpass.getuser()/\"$USER\"/" /usr/bin/blih
    echo "user set"
fi
grep -q "getpass.getpass()" /usr/bin/blih
OUT=$?
if [ $OUT -eq 1 ]
then
    echo "Could not find password section"
    exit 1
else
    sed -i "s/getpass.getpass()/\"$PASSWORD\"/" /usr/bin/blih
fi
echo "blih file modification : success"    
echo "Creating binary file 'repo'"
make
make clean
echo "Binary created, moving to /usr/bin"
mv repo /usr/bin/
echo "Binary moved, You can now use the program using the 'repo' command"
echo "To know more about the command, type 'repo --help'"
