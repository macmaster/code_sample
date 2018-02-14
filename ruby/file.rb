file = File.open(ARGV[0] ? ARGV[0] : "account.rb")
file.each { |line| puts line }
file.close
