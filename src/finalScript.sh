#Par Duprat Dorian et Piekarz Alexis
#Date: 27/11/2022
#Description: Script d'installation de l'environnement de travail pour Tek-it-Izi complétement automatisé
#Version: 1.0
#!/bin/bash

echo "Bienvenue dans le script d'installation de l'environnement de travail pour Tek-it-Izi"
echo "Veuillez patienter pendant l'installation de l'environnement de travail"


#Update system
sudo apt-get update
sudo apt-get upgrade

#Install firefox browser
sudo apt-get install firefox


#Install chrome browser
sudo apt-get install chromium-browser


#Install git
sudo apt-get install git


#Install vscode
sudo snap install --classic code


# create the group
groupadd DEV
groupadd WEB
groupadd MARK


# define group administrators
gpasswd -A emusk DEV
gpasswd -A jbezos WEB
gpasswd -A barnault MARK


# adding CHEF folders
groupadd CHEF
gpasswd -a emusk CHEF
gpasswd -a jbezos CHEF
gpasswd -a barnault CHEF
cd ~/..


# creating group directories
mkdir dev web marketing partageTous partageChefs


# DEV
chgrp -R DEV dev/
chmod 770 dev
cd dev/
mkdir partageDev


# WEB
cd ../
chgrp -R WEB web/
chmod 770 web
cd web
mkdir partageWeb


# MARK
cd ../
chgrp -R MARK marketing/
chmod 770 marketing
cd marketing
mkdir partageMark


# CHEF
cd ../
chgrp -R CHEF partageChefs/
chmod 770 partageChefs


cd home
ls

# cd ~
# cd ../../etc
# echo `cat group`

# récup tous les utilisateurs sauf les chefs de groupe
for ligne in `cat collabos.csv | tail -n 47`
do

	# Vérifie les variables
	prenom=`echo $ligne|cut -d ';' -f 1 | tr [:upper:] [:lower:]`
	nom=`echo $ligne|cut -d ';' -f 2 | tr [:upper:] [:lower:]`
#	echo "mdp : `echo $ligne|cut -d ';' -f 3`"
	dpt=`echo $ligne|cut -d ';' -f 4`
#	echo "---------------------------"
	# Récupère le login
	login="${prenom:0:1}${nom:0:7}"
	echo $login

	# les if pour ajouter aux groupes
	echo $dpt
	case "$dpt" in
		DEV ) gpasswd -a $login DEV;;
		WEB ) gpasswd -a $login WEB;;
		MARK ) gpasswd -a $login MARK;;
		* ) echo "Groupe invalide";;
	esac
done

