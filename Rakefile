require 'asciidoctor'
require 'asciidoctor-revealjs'

#        :backend => 'dzslides',
#        :template_dir => 'asciidoctor-backends/slim/'

desc "Generate html pages using reveal.js"
task :generate, [:filename, :output_dir] do |t, args|
    filename = args[:filename]
    puts args
    #TODO(shearer) use asciidoctor-revealjs directly, not through shell
    sh 'bundle exec asciidoctor-revealjs -a revealjsdir=https://cdnjs.cloudflare.com/ajax/libs/reveal.js/3.3.0 ' + filename
end

task :default do
     task(:generate).invoke('index.adoc')
end
