ifconfig | grep '^\tether' | tr -d '\t' | sed 's/ether //' | sed 's/ $//'
