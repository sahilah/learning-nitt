if test 6 -lt 56 #"then" needs the exit status of the command test.. 0 or something else.. 0 means successful (no error)
  then echo "hi"
fi  # cant be dropped like in C in any case

# -lt/gt lesser/greater than -le/ge or equal to -ne not equal to -eq equal to

#test[ -f $fname ]     -s size>0 -f exists and is file -d exists and is directory -k exists and has sticky bit set to it
#    -r/w/x exists and has read/write/execute persmission

#Tests on strings
#Condition                True if
#string1 = (!=) sting2    same (not same)
#-n string (-z)           string length > 0 (=0)
#string                   if not null

# $? -- stores the result of any prior test
# tests can be performed without the test statement directly by [6 -gt 7]

#a=b is assignment, $a = $b is comparison
# -o or -a and ! not
# else + if = elif
who am i | cut -f 1 -d " " #cut field 1 (or -c for column) from o/p with delimiter space
echo Enter choice 1 or 2
read choice
case $choice in
  1)  echo Entered 1
      ;;
  2)  echo Entered 2
      ;;
  *)  echo You are `who am i | cut -f 1 -d " "` #cut field 1 (or -c for column) from o/p with delimiter space
      ;;
esac

#while[]
# do
#
# done
