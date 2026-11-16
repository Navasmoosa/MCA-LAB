<?PHP
$num1 =10;
$num2 =20;
$num3 =15;
if($num1>$num2 && $num1>$num3){
    echo("$num1 is geatest");
}
elseif($num2>$num1 && $num2>$num3){
    echo("$num2 is greatest");
}
else
{
    echo("$num3 is greatest");
}