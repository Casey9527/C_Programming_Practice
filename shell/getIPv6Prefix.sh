# PUBLIC_IP="0ff8:800f:f880:0f08:d88a:d413:bdaf:b488"
# NETMASK="64"
# GATEWAY="fe80:0000:0000:0000:f92e:14a1:5084:bff0"
# DNSSERVERS=""

# getIPv6Prefix $PUBLIC_IP $NETMASK
getIPv6Prefix() {
	full_groups_end=$(($NETMASK / 16))
	partial_group_begin=$(($full_groups_end + 1))
	partial_group_width=$(($NETMASK % 16))

	local groups_full
	groups_full=$(echo $PUBLIC_IP | cut -d':' -f 1-$full_groups_end)

	if [ "$partial_group_width" -eq "0" ]; then
		printf "${groups_full}"
	else
		local group_partial mask_hex last_group_hex last_group_masked
		group_partial=$(echo $PUBLIC_IP | cut -d':' -f $partial_group_begin)
		mask_zero=$(printf "0x%x\n" "$(( $((1 << (16 - $partial_group_width))) - 1))")
		mask_word=$(printf "0x%x\n" "$(( $((1 << 16)) - 1))")
		mask_hex=$(printf "0x%x\n" "$(( $(($mask_word)) ^ $mask_zero))")
		last_group_hex="0x${group_partial}"
		last_group_masked=$(printf "%x\n" "$(( $(($last_group_hex)) & $mask_hex))")
		printf "${groups_full}:${last_group_masked}"
	fi
}

PUBLIC_IP="0ff8:800f:f880:0f08:d88a:d413:bdaf:b488"
NETMASK="64"

IPV6_PREFIX=$(getIPv6Prefix $PUBLIC_IP $NETMASK)
echo $IPV6_PREFIX
