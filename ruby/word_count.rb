def parse_words(string)
	string.downcase.scan(/[\w']+/)
end

def count_words(word_list)
	counts = Hash.new(0)
  word_list.each { |word| counts[word] += 1 }
	return counts
end

if __FILE__ == $0
	phrase = "Well ain't this a nice day now partner? I when you tell a person how they feel!"
	word_count = count_words(parse_words(phrase))
	p word_count
end
