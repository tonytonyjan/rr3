$: << File.expand_path('../../ext', __FILE__)
require 'spec_helper'

describe Rr3 do
  it 'works' do
    t = Rr3::Tree.new(10)
    t.insert_path "/foo/bar"
    t.compile!
    expect(t.match("/foo/bar")).to  be true
    expect(t.match("/foo/barr")).to  be false
    t.dump(0)
  end
end
