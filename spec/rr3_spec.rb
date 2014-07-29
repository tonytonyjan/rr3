$: << File.expand_path('../../ext', __FILE__)
require 'spec_helper'

describe Rr3 do
  it 'works' do
    t = Rr3::Tree.new(10)
    t.insert_path "/foo/bar"
    t.dump(0)
  end
end
