def Integer.all
  Enumerator.new do |yielder, n: 0|
    loop { yielder.yield(n += 1) }
  end.lazy
end

def palindrome?(n)
  n = n.to_s
  n == n.reverse
end

def n_times(thing)
  lambda {|n| thing * n}
end

def power(base = 2)
  value = 1
  -> { value *= base }
end

p Integer
  .all
  .select { |i| (i % 3).zero? }
  .select { |i| (i % 4).zero? }
  .select { |i| palindrome?(i) }
  .first(30)

count = power(2) 
10.times { p count.call }
