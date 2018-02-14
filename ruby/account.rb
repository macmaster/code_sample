class Account
  attr_reader :balance
  protected :balance

  def initialize(balance)
    @balance = balance
  end

  def compare_to(other)
    if other.nil? || !other.is_a?(Account)
      return nil
    elsif @balance > other.balance
      return 1
    elsif @balance == other.balance
      return 0
    elsif @balance < other.balance
      return -1
    else
      return nil
    end
  end
  
  def name(*args)
    if !args.empty?
      puts args.inspect
    end
    Account.class
  end
end

class SpecialAccount < Account
  def name(*)
    STDERR.puts "special name..."
    super
  end
end

class Tax
  def initialize(name, &block)
    @name, @block = name, block
  end

  def get_tax(amount)
    "#{@name} on #{amount} = #{@block.call(amount)}"
  end

  def get_tax?(amount)
    self.get_tax(amount)
  end
end

