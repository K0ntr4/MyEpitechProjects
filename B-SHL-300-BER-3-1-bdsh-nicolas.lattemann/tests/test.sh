file="test_file.json"

if [[ -f $file ]]; then
    rm $file;
fi

#before creation, verfies correct error managment
./bdsh -f $file create table user id,age,first_name,last_name,favourite_colour
echo $?
./bdsh -f $file insert game id=1,name=Terraria,developer=505
echo $?
./bdsh -f $file update game developer="Riot Games" where developer="Riot"
echo $?
./bdsh -f test_file.json select user age,first_name,last_name orderby age
echo $?
./bdsh -f $file create database
./bdsh -f $file update game developer="Riot Games" where developer="Riot"
echo $?
./bdsh -f $file create table user id,age,first_name,last_name,favourite_colour
./bdsh -f test_file.json select usr age,first_name,last_name orderby age



rm $file

#feature tests
./bdsh -f $file create database
./bdsh -f $file create table user id,age,first_name,last_name,favourite_colour
./bdsh -f $file create table game id,name,developer
./bdsh -f $file insert game id=1,name=Terraria,developer=505
./bdsh -f $file insert game id=2,name="League of Legends",developer="Riot"
./bdsh -f $file insert game id=3,name="Valorant",developer="Riot"
./bdsh -f $file insert game id=4,name="Skyrim",developer="Bethesda"
./bdsh -f $file update game developer="Riot Games" where developer="Riot"
./bdsh -f $file insert user id=1,age=19,first_name=Luca,last_name=blank,favourite_colour=red
./bdsh -f $file insert user id=2,age=21,first_name=Nicolas,last_name=blank,favourite_colour=green
./bdsh -f test_file.json select user age,first_name,last_name orderby age
echo
./bdsh -f test_file.json select user age,first_name,last_name
echo
./bdsh -f test_file.json select game id,name,developer orderby id
echo
./bdsh -f test_file.json select game id,name,developer orderby developer
echo
./bdsh -f test_file.json select game id,name,developer
echo
./bdsh -f test_file.json select game id,name,developer orderby id where developer="Riot Games"
echo
./bdsh -f test_file.json select game id,name,developer where developer="Riot Games" orderby id
echo
./bdsh -f test_file.json select game id,name,developer orderby id
echo
./bdsh -f test_file.json select game id,name,developer where developer="Riot Games"
echo
./bdsh -f test_file.json select game id,name,developer where developer="Riot Games" -j