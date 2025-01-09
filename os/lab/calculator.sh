echo "enter the number"
read r1
read r2
echo "enter the operands(1='+',2='-',3='*',4='/')"
read operand 
case $operand in
1)result=$(($r1+$r2))
echo "the result is $result";;
2)result=$(($r1-$r2))
echo "the result is $result";;
3)result=$(($r1*$r2))
echo "the result is $result";;
4)result=$(($r1/$r2))
echo "the result is $result";;
*)echo "invalid";;
esac
