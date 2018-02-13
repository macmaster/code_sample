require_relative "word_count.rb"
require "test/unit"

class TestWordCount
	def test_empty
		assert_equal([], parse_words(""))
		assert_equal([], parse_words(" "))
	end

	def test_single_word
		assert_equal(["cat"], parse_words("cat"))
		assert_equal(["cat"], parse_words("   cat   "))
	end

	def test_many_words
		assert_equal(%w(one two three four), parse_words("one two three four"))
	end
end

