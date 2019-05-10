PUBLIC_IP="192.168.48.171"
NETMASK="255.255.255.248"
GATEWAY="192.168.48.172"
DNSSERVERS=""

# num2binary $DECIMAL_NUM
num2binary() {
	n="$1"
	bit=""
	while [ "$n" -gt 0 ]; do
		bit="$(( n&1 ))$bit";
		: $(( n >>= 1 ))
	done
	printf "%s\n" "$bit"
}

# getNetmaskPrefixLength $NETMASK
getNetmaskPrefixLength() {
	decimal=$(echo $1 | awk -F '.' '{print ($1 * (2^24) + $2 * (2^16) + $3 * (2^8) + $4)}')
	binary=$(num2binary $decimal)
	echo $binary | awk -F '0' '{print length($1)}'
}

# getNetworkAddress $PUBLIC_IP $NETMASK
getNetworkAddress() {
	i1=$(echo $PUBLIC_IP | tr "." " " | awk '{ print $1}')
	i2=$(echo $PUBLIC_IP | tr "." " " | awk '{ print $2}')
	i3=$(echo $PUBLIC_IP | tr "." " " | awk '{ print $3}')
	i4=$(echo $PUBLIC_IP | tr "." " " | awk '{ print $4}')

	m1=$(echo $NETMASK | tr "." " " | awk '{ print $1}')
	m2=$(echo $NETMASK | tr "." " " | awk '{ print $2}')
	m3=$(echo $NETMASK | tr "." " " | awk '{ print $3}')
	m4=$(echo $NETMASK | tr "." " " | awk '{ print $4}')

	NETWORK_ADDRESS="$((i1 & m1))"."$((i2 & m2))"."$((i3 & m3))"."$((i4 & m4))"
	echo $NETWORK_ADDRESS
}



NETWORK_ADDRESS=$(getNetworkAddress $PUBLIC_IP $NETMASK)
echo $NETWORK_ADDRESS

NETMASK_PREFIX_LENGTH=$(getNetmaskPrefixLength $NETMASK)
echo $NETMASK_PREFIX_LENGTH
