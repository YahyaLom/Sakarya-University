<?php

$curl = curl_init();

curl_setopt_array($curl, [
	CURLOPT_URL => "https://instagram47.p.rapidapi.com/public_post_comments?shortcode=CU4lZWkojkY",
	CURLOPT_RETURNTRANSFER => true,
	CURLOPT_FOLLOWLOCATION => true,
	CURLOPT_ENCODING => "",
	CURLOPT_MAXREDIRS => 10,
	CURLOPT_TIMEOUT => 30,
	CURLOPT_HTTP_VERSION => CURL_HTTP_VERSION_1_1,
	CURLOPT_CUSTOMREQUEST => "GET",
	CURLOPT_HTTPHEADER => [
		"X-RapidAPI-Host: instagram47.p.rapidapi.com",
		"X-RapidAPI-Key: SIGN-UP-FOR-KEY"
	],
]);

$response = curl_exec($curl);
$err = curl_error($curl);

curl_close($curl);

if ($err) {
	echo "cURL Error #:" . $err;
} else {
	echo $response;
}