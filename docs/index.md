
<img src="assets/images/branding/glimpse_logo_400x171.png" align="right" alt="GLIMPSE2_logo" style="height:150px">

<div class="tight-paragraphs">
  <h1> GLIMPSE </h1>
  <p>A tool for low-coverage whole-genome sequencing imputation</p>
</div>

<br>
<br>

## About

[GLIMPSE2](https://www.biorxiv.org/content/10.1101/2022.11.28.518213v1) is a set of tools for low-coverage whole genome sequencing imputation. GLIMPSE2 is based on the <a href="https://www.nature.com/articles/s41588-020-00756-0">GLIMPSE model</a> and designed for reference panels containing hundreads of thousands of reference samples, with a special focus on rare variants. 

## Citation

If you use GLIMPSE in your research work, please cite the following papers:

[Rubinacci et al., Imputation of low-coverage sequencing data from 150,119 UK Biobank genomes. BiorXiv (2022)](https://www.biorxiv.org/content/10.1101/2022.11.28.518213v1)

[Rubinacci et al., Efficient phasing and imputation of low-coverage sequencing data using large reference panels. Nature Genetics 53.1 (2021): 120-126.](https://www.nature.com/articles/s41588-020-00756-0)


[Get started now](#getting-started){: .btn .btn-primary .fs-5 .mb-4 .mb-md-0 .mr-2 .mx-auto }
[View source code on GitHub](https://github.com/odelaneau/GLIMPSE){: .btn .fs-5 .mb-4 .mb-md-0 }


## GLIMPSE1

At the moment, GLIMPSE2 performs imputation only from a reference panel of samples. 
To use the joint-model, particularly useful for many samples at higher coverages (>0.5x) and small reference panels, please visit the [GLIMPSE1 website](https://odelaneau.github.io/GLIMPSE/glimpse1/index.html).

## News

!!! info "NEW"
    **Version `2.0.0` is now available!**
    See [the CHANGELOG](https://github.com/odelaneau/GLIMPSE/blob/master/docs/CHANGELOG.md) for details.

## Description

GLIMPSE2 is composed of the following tools:

- **chunk**. Tool to phase common sites, typically SNP array data, or the first step of WES/WGS data.
- **split_reference**. Tool to phase common sites, typically SNP array data, or the first step of WES/WGS data.
- **phase**. Ligate multiple phased BCF/VCF files into a single whole chromosome file. Typically run to ligate multiple chunks of phased common variants.
- **ligate**. Tool to phase rare variants onto a scaffold of common variants (output of phase_common / ligate).
- **concordance**. Program to compute switch error rate and genotyping error rate given simulated or trio data.

[chunk]({{site.baseurl}}{% link docs/documentation/chunk.md %}){: .btn .btn-blue }
[split_reference]({{site.baseurl}}{% link docs/documentation/split_reference.md %}){: .btn .btn-blue }
[phase]({{site.baseurl}}{% link docs/documentation/phase.md %}){: .btn .btn-blue }
[ligate]({{site.baseurl}}{% link docs/documentation/ligate.md %}){: .btn .btn-blue }
[concordance]({{site.baseurl}}{% link docs/documentation/concordance.md %}){: .btn .btn-blue  }

---

## Getting started

- [See documentation]({{site.baseurl}}{% link docs/documentation/documentation.md  %} )

---

## About the project

GLIMPSE is developed by Simone Rubinacci & Olivier Delaneau.

### License

GLIMPSE is distributed with [MIT license](https://github.com/odelaneau/GLIMPSE/blob/master/LICENSE).

### Organisations

<div class="logo-bar">
  <div class="logo"><a href="https://www.unil.ch/index.html"><img src="assets/images/lausanne_logo.jpg" alt="unil" style="height:50px"></a></div>
  <div class="logo"><a href="https://www.sib.swiss/"><img src="assets/images/sib_logo.jpg" alt="sib" style="height:50px"></a></div>
  <div class="logo"><a href="https://www.snf.ch/en/Pages/default.aspx"><img src="assets/images/snf.gif" alt="snf" style="height:50px"></a></div>
</div>

### Contributing

GLIMPSE is an open source project and we very much welcome new contributors. To make the contribution quickly accepted, please first discuss the change you wish to make via issue,
email, or any other method with the owners of this repository before making a change.

#### Thank you to the contributors of GLIMPSE!

<ul class="list-style-none">
{% for contributor in site.github.contributors %}
  <li class="d-inline-block mr-1">
     <a href="{{ contributor.html_url }}"><img src="{{ contributor.avatar_url }}" width="32" height="32" alt="{{ contributor.login }}"/></a>
  </li>
{% endfor %}
</ul>
