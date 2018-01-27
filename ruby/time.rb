def start_msg(timestamp)
  "The ruby journey begins...\n" \
  "The current time is #{timestamp}"
end

msg = start_msg(Time.now)
puts msg

