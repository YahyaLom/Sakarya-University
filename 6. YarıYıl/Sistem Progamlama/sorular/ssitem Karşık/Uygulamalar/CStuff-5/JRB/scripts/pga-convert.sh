# Cut and paste the golfer lines from the "PAST RESULTS" link on pgatour.com

if [ $# -ne 1 ]; then
  echo 'usage: sh pga-convert.sh 72-hole-par' >&2
  exit 1
fi
awk '{ for (i = 1; i <= NF; i++) printf "%s ", $i; print "" }' |
sed -e '1,$s/\$.*//' -e '1,$s/ *$//' -e 's/ T*[0-9].* /    /' | awk '{ print ($NF-'$1'), $0 }' |
  sed '/^[0-9]/s/^/+/' |
  sed 's/\([+-][0-9]*\) \(.*[^ ]\)    *.*/\2                                         XX F \1/' |
  sed 's/\(.....................................\) */\1/'
