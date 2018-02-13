def start_msg(timestamp)
  "The ruby journey begins...\n" \
  "The current time is #{timestamp}"
end

def walk(direction, num_paces)
  if direction == :north
    puts "walking #{direction} #{num_paces} paces."
  elsif direction == :east
    puts "walking #{direction} #{num_paces} paces."
  elsif direction == :south
    puts "walking #{direction} #{num_paces} paces."
  elsif direction == :west
    puts "walking #{direction} #{num_paces} paces."
  else
    puts "bad walking direction."
  end
end

def call_block
  puts "start call_block"
  yield
  yield
  puts "middle call_block"
  yield
  puts "end call_block"
end

msg = start_msg(Time.now)
puts msg

# array = [ 1, "nice", 3.14, nil]
# puts "The array declared on line 9 is: #{array.inspect}"
# 
# puts "invocation of the %W built-in shortcut"
# array = %W(
#   sometimes
#   life
#   can be
#   a little
#   irritating
#   #{array.inspect}
# )
# puts array.inspect
# 
# histogram = Hash.new(-1)
# histogram[:north] = "north"
# histogram[:east] = "east"
# histogram[:south] = "south"
# histogram[:west] = "west"
# puts "histogram[:up] = #{histogram[:up]}"
# 
# puts "\n" # banner
# puts "beginning backpack trip:"
# walk(:north, 5)
# walk(:south, 4)
# walk(:west, 0)
# walk(:east, -6)
# walk(:up, 6)
# 
# i = 6
# while i > 0 and true
#   puts "#{i -= 1}) times. lemme see you do it 2 times."
# end

# # shell
# print "$ "
# while line = gets
#   # puts line.upcase
#   if line =~ /(perl|python)/
#     puts "nice try buddy! that's a banned command."
#   else
#     system( line )
#   end
#   print "$ "
# end
# puts ""

string = "This is a really long string with a few misnomers and what not brother...."
puts "original: #{string}"
puts "substituted: #{string.gsub(/[aeiou]/, 'x')}"

call_block { puts "wow.wow.wow!" }
