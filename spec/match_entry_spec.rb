require 'spec_helper'

describe Rr3::MatchEntry do
  it '#initialize' do
    x = Rr3::MatchEntry.new path: 'asdf', a: 123
  end
end