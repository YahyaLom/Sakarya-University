<?php


if(!($_POST['mail']==""))
{
echo "Mesaj Gönderme başarılı...";
echo "<br />Adınınz ve Soyadınız : ";
echo $_POST ['ad'] ; error_reporting(0);
echo "<br / >e-mail adresiniz : ";
echo $_POST ['mail'];
echo "<br />Cinsiyet : ";
echo $_POST ['cinsiyet'];
echo "<br / >Eğitim durumunuz : ";
echo $_POST ['edc'];
echo "<br />Hakim Diller : ";
$diller = $_POST['dil'];
foreach ($diller as $key )
{
    echo $key;
}

echo "<br />Şehir : ";
echo $_POST ['sehrim'];
echo "<br />Mesajınız : <br />";
echo $_POST ['mesaj'];

}else 
{
    echo "e-mail girmek zorunlu alan";
}
echo "<p> <a href='indexBootstrap.html'>&lt;ANA SAYFA&gt;</a></p> ";
echo "<p> <a href='iletisim.html'>&lt;GERİ DÖN&gt;</a></p> ";
    





?>