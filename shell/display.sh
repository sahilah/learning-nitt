name=sahil

#tput bel      no bell character

tput bold
echo "HI GUYS!!"
echo "Total no of column on screen = "
tput lines 
tput cols
#read a
tput rev # or tput smso
tput cup 10 10
echo 123
echo "here's the reverse effect!!"
tput rmso
tput blink
echo continue\?
read a
tput reset

