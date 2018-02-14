def parse_words(string)
  string.downcase.scan(/[\w']+/)
end

def count_words(word_list)
  counts = Hash.new(0)
  word_list.each { |word| counts[word] += 1 }
  return counts
end

if __FILE__ == $0
  phrase = \
    "Well ain't this a nice day now partner? I when you tell a person how they feel!\n" \
    "Can't you just tell them to call it a day sometime? I'm really exhausted!\n" \
    "Writing all of this software can be a little draining sometimes to be quite honest with you.\n" \

  word_count = count_words(parse_words(phrase))
  word_count = word_count.sort_by { |word, count| count }
  puts word_count.reverse.map { |word, count| "#{word}: #{count}" }
end
