class Book
	attr_reader :isbn
	attr_reader :price
	attr_accessor :price

	def initialize(isbn, price)
		@isbn = isbn
		@price = price
	end

	def stat
		@isbn * @price
	end

	def err
		ARGV.each do |arg|
			STDERR.puts arg
		end
	end
end
